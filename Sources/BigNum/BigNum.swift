///
/// BigNum.swift
/// A swift wrapper for BIGNUM functions in OpenSSL library
/// Inspired by the implementation here https://github.com/Bouke/Bignum
///

import CBigNum
import Foundation

/// Swift wrapper class for BIGNUM functions in OpenSSL library
public final class BigNum {
    // ctx is an `OpaquePointer` because in OpenSSL 1.1 `BIGNUM` is an incomplete type. Still have to jump
    // through hoops though because in other builds it is complete type and the compiler complains about
    // casting to and from an OpaquePointer
    internal let ctx: OpaquePointer?
    
    public init() {
        ctx = BN_new().convert()
    }
    
    public init(_ int: Int) {
        let ctx = BN_new()
        withUnsafePointer(to: int.bigEndian) { bytes in
            let raw = UnsafeRawPointer(bytes)
            let p = raw.bindMemory(to: UInt8.self, capacity: MemoryLayout<Int>.size)
            BN_bin2bn(p, Int32(MemoryLayout<Int>.size), ctx)
        }
        self.ctx = ctx!.convert()
    }

    public init?(_ dec: String) {
        var ctx = BN_new()
        if BN_dec2bn(&ctx, dec) == 0 {
            return nil
        }
        self.ctx = ctx!.convert()
    }

    public init?(hex: String) {
        var ctx = BN_new()
        if BN_hex2bn(&ctx, hex) == 0 {
            return nil
        }
        self.ctx = ctx!.convert()
    }

    public init(data: Data) {
        let ctx = BN_new()
        _ = data.withUnsafeBytes { bytes in
            let p = bytes.bindMemory(to: UInt8.self)
            BN_bin2bn(p.baseAddress, Int32(data.count), ctx)
        }
        self.ctx = ctx!.convert()
    }

    deinit {
        BN_free(ctx?.convert())
    }

    public var data: Data {
        var data = Data(count: Int((BN_num_bits(ctx?.convert()) + 7) / 8))
        _ = data.withUnsafeMutableBytes { bytes in
            let p = bytes.bindMemory(to: UInt8.self)
            BN_bn2bin(ctx?.convert(), p.baseAddress)
        }
        return data
    }

    public var dec: String {
        return String(validatingUTF8: BN_bn2dec(ctx?.convert()))!
    }

    public var hex: String {
        return String(validatingUTF8: BN_bn2hex(ctx?.convert()))!
    }
}

extension BigNum: CustomStringConvertible {
    public var description: String {
        return dec
    }
}

extension BigNum: Comparable {
    public static func == (lhs: BigNum, rhs: BigNum) -> Bool {
        return BN_cmp(lhs.ctx?.convert(), rhs.ctx?.convert()) == 0
    }

    public static func < (lhs: BigNum, rhs: BigNum) -> Bool {
        return BN_cmp(lhs.ctx?.convert(), rhs.ctx?.convert()) == -1
    }
}

extension BigNum: ExpressibleByIntegerLiteral {
    public typealias IntegerLiteralType = Int

    public convenience init(integerLiteral value: Int) {
        self.init(value)
    }
}

//MARK: Operations

extension BigNum {
    static func operation(_ block: (_ result: BigNum) -> Int32) -> BigNum {
        let result = BigNum()
        precondition(block(result) == 1)
        return result
    }

    static func operationWithCtx(_ block: (BigNum, OpaquePointer?) -> Int32) -> BigNum {
        let result = BigNum()
        let context = BN_CTX_new()
        precondition(block(result, context) == 1)
        BN_CTX_free(context)
        return result
    }
}

public func + (lhs: BigNum, rhs: BigNum) -> BigNum {
    return BigNum.operation {
        BN_add($0.ctx?.convert(), lhs.ctx?.convert(), rhs.ctx?.convert())
    }
}

public func - (lhs: BigNum, rhs: BigNum) -> BigNum {
    return BigNum.operation {
        BN_sub($0.ctx?.convert(), lhs.ctx?.convert(), rhs.ctx?.convert())
    }
}

public func * (lhs: BigNum, rhs: BigNum) -> BigNum {
    return BigNum.operationWithCtx {
        BN_mul($0.ctx?.convert(), lhs.ctx?.convert(), rhs.ctx?.convert(), $1)
    }
}

/// Returns lhs / rhs, rounded to zero.
public func / (lhs: BigNum, rhs: BigNum) -> BigNum {
    return BigNum.operationWithCtx {
        BN_div($0.ctx?.convert(), nil, lhs.ctx?.convert(), rhs.ctx?.convert(), $1)
    }
}

/// Returns lhs / rhs, rounded to zero.
public func % (lhs: BigNum, rhs: BigNum) -> BigNum {
    return BigNum.operationWithCtx {
        BN_div(nil, $0.ctx?.convert(), lhs.ctx?.convert(), rhs.ctx?.convert(), $1)
    }
}

/// right shift
public func >> (lhs: BigNum, shift: Int32) -> BigNum {
    return BigNum.operation {
        BN_rshift($0.ctx?.convert(), lhs.ctx?.convert(), shift)
    }
}

/// left shift
public func << (lhs: BigNum, shift: Int32) -> BigNum {
    return BigNum.operation {
        BN_lshift($0.ctx?.convert(), lhs.ctx?.convert(), shift)
    }
}

//MARK: Member Operations

public extension BigNum {

    /// Returns: (self ** 2)
    func sqr() -> BigNum {
        return BigNum.operationWithCtx {
            BN_sqr($0.ctx?.convert(), self.ctx?.convert(), $1)
        }
    }

    /// Returns: (self ** p)
    func power(_ p: BigNum) -> BigNum {
        return BigNum.operationWithCtx {
            BN_exp($0.ctx?.convert(), self.ctx?.convert(), p.ctx?.convert(), $1)
        }
    }
    
    /// Returns: (self + b) % N
    func add(_ b: BigNum, modulus: BigNum) -> BigNum {
        return BigNum.operationWithCtx {
            BN_mod_add($0.ctx?.convert(), self.ctx?.convert(), b.ctx?.convert(), modulus.ctx?.convert(), $1)
        }
    }

    /// Returns: (a - b) % N
    func sub(_ b: BigNum, modulus: BigNum) -> BigNum {
        return BigNum.operationWithCtx {
            BN_mod_sub($0.ctx?.convert(), self.ctx?.convert(), b.ctx?.convert(), modulus.ctx?.convert(), $1)
        }
    }

    /// Returns: (a * b) % N
    func mul(_ b: BigNum, modulus: BigNum) -> BigNum {
        return BigNum.operationWithCtx {
            BN_mod_mul($0.ctx?.convert(), self.ctx?.convert(), b.ctx?.convert(), modulus.ctx?.convert(), $1)
        }
    }

    /// Returns: (a ** 2) % N
    func sqr(modulus: BigNum) -> BigNum {
        return BigNum.operationWithCtx {
            BN_mod_sqr($0.ctx?.convert(), self.ctx?.convert(), modulus.ctx?.convert(), $1)
        }
    }

    /// Returns: (a ** p) % N
    func power(_ p: BigNum, modulus: BigNum) -> BigNum {
        return BigNum.operationWithCtx {
            BN_mod_exp($0.ctx?.convert(), self.ctx?.convert(), p.ctx?.convert(), modulus.ctx?.convert(), $1)
        }
    }
    
    /// Return greatest common denominator
    static func gcd(_ first: BigNum, _ second: BigNum) -> BigNum {
        return operationWithCtx {
            BN_gcd($0.ctx?.convert(), first.ctx?.convert(), second.ctx?.convert(), $1)
        }
    }
    
    /// Bitwise operations

    func setBit(_ bit: Int32) {
        BN_set_bit(self.ctx?.convert(), bit)
    }
    
    func clearBit(_ bit: Int32) {
        BN_clear_bit(self.ctx?.convert(), bit)
    }
    
    func mask(_ bits: Int32) {
        BN_mask_bits(self.ctx?.convert(), bits)
    }

    func isBitSet(_ bit: Int32) -> Bool {
        let set = BN_is_bit_set(self.ctx?.convert(), bit)
        return set == 1 ? true : false
    }

    func numBits() -> Int32 {
        return BN_num_bits(self.ctx?.convert())
    }
    
    /// random number generators
    
    enum Top: Int32 {
        case any = -1
        case topBitSetToOne = 0
        case topTwoBitsSetToOne = 1
    }

    /// return cryptographically strong random number of maximum size defined in bits. random needs seeding prior to be called
    static func random(bits: Int32, top: Top = .any, odd: Bool = false) -> BigNum {
        return operation {
            BN_rand($0.ctx?.convert(), bits, top.rawValue, odd ? 1 : 0)
        }
    }
    
    /// return pseudo random number of maximum size defined in bits.
    static func psuedo_random(bits: Int32, top: Top = .any, odd: Bool = false) -> BigNum {
        return operation {
            BN_pseudo_rand($0.ctx?.convert(), bits, top.rawValue, odd ? 1 : 0)
        }
    }
    
    /// return cryptographically strong random number in range (0...max-1). random needs seeding prior to be called
    static func random(max: BigNum) -> BigNum {
        return operation {
            BN_rand_range($0.ctx?.convert(), max.ctx?.convert())
        }
    }
    
    /// return pseudo random number in range (0..<max)
    static func psuedo_random(max: BigNum) -> BigNum {
        return operation {
            BN_pseudo_rand_range($0.ctx?.convert(), max.ctx?.convert())
        }
    }
    
    /// prime number generator
    static func generatePrime(bitSize: Int32, safe: Bool, add: BigNum? = nil, remainder: BigNum? = nil) -> BigNum {
        return operation {
            BN_generate_prime_ex($0.ctx?.convert(), bitSize, safe ? 1 : 0, add?.ctx?.convert(), remainder?.ctx?.convert(), nil)
        }
    }
    
    /// prime number generator
    func isPrime(numChecks: Int32) -> Bool {
        let context = BN_CTX_new()
        defer {
            BN_CTX_free(context)
        }
        return BN_is_prime_ex(self.ctx?.convert(), numChecks, context, nil) == 1
    }
}

/// extensions taken from swift-nio
extension OpaquePointer {
    func convert<T>() -> UnsafeMutablePointer<T> {
        return .init(self)
    }

    func convert() -> OpaquePointer {
        return self
    }
}

extension UnsafeMutablePointer {
    func convert() -> OpaquePointer {
        return .init(self)
    }
}

