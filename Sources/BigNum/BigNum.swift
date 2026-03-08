///
/// BigNum.swift
/// A swift wrapper for BIGNUM functions in BoringSSL library
/// Inspired by the implementation here https://github.com/Bouke/Bignum
///

internal import CBigNumBoringSSL

#if canImport(FoundationEssentials)
public import FoundationEssentials
#else
public import Foundation
#endif

/// Swift wrapper class for BIGNUM functions in BoringSSL library
public final class BigNum {
    internal let ctx: UnsafeMutablePointer<BIGNUM>?

    public init() {
        self.ctx = CBigNumBoringSSL_BN_new()
    }

    public init(_ int: Int) {
        let ctx = CBigNumBoringSSL_BN_new()
        withUnsafePointer(to: int.bigEndian) { bytes in
            let raw = UnsafeRawPointer(bytes)
            let p = raw.bindMemory(to: UInt8.self, capacity: MemoryLayout<Int>.size)
            CBigNumBoringSSL_BN_bin2bn(p, Int(MemoryLayout<Int>.size), ctx)
        }
        self.ctx = ctx
    }

    public init?(_ dec: String) {
        var ctx = CBigNumBoringSSL_BN_new()
        if CBigNumBoringSSL_BN_dec2bn(&ctx, dec) == 0 {
            return nil
        }
        self.ctx = ctx
    }

    public init?(hex: String) {
        var originalCtx = CBigNumBoringSSL_BN_new()
        if CBigNumBoringSSL_BN_hex2bn(&originalCtx, hex) == 0 {
            CBigNumBoringSSL_OPENSSL_free(originalCtx)
            return nil
        }
        self.ctx = originalCtx
    }

    public init<D: ContiguousBytes>(bytes: D) {
        let ctx = CBigNumBoringSSL_BN_new()
        bytes.withUnsafeBytes { bytes in
            if let p = bytes.baseAddress?.assumingMemoryBound(to: UInt8.self) {
                CBigNumBoringSSL_BN_bin2bn(p, .init(bytes.count), ctx)
            }
        }
        self.ctx = ctx
    }

    deinit {
        CBigNumBoringSSL_BN_free(ctx)
    }

    public var data: Data {
        var data = Data(count: Int((CBigNumBoringSSL_BN_num_bits(ctx) + 7) / 8))
        data.withUnsafeMutableBytes { bytes in
            if let p = bytes.baseAddress?.assumingMemoryBound(to: UInt8.self) {
                CBigNumBoringSSL_BN_bn2bin(self.ctx, p)
            }
        }
        return data
    }

    public var bytes: [UInt8] {
        var bytes = [UInt8].init(
            repeating: 0,
            count: Int((CBigNumBoringSSL_BN_num_bits(self.ctx) + 7) / 8)
        )
        bytes.withUnsafeMutableBytes { bytes in
            if let p = bytes.baseAddress?.assumingMemoryBound(to: UInt8.self) {
                CBigNumBoringSSL_BN_bn2bin(self.ctx, p)
            }
        }
        return bytes
    }

    public var dec: String {
        guard let cString = CBigNumBoringSSL_BN_bn2dec(self.ctx) else { return "" }
        defer { CBigNumBoringSSL_OPENSSL_free(cString) }
        return String(cString: cString)
    }

    public var hex: String {
        guard let cString = CBigNumBoringSSL_BN_bn2hex(self.ctx) else { return "" }
        defer { CBigNumBoringSSL_OPENSSL_free(cString) }
        return String(cString: cString)
    }
}

extension BigNum: CustomStringConvertible {
    public var description: String {
        self.dec
    }
}

extension BigNum: Comparable {
    public static func == (lhs: BigNum, rhs: BigNum) -> Bool {
        CBigNumBoringSSL_BN_equal_consttime(lhs.ctx, rhs.ctx) == 1
    }

    public static func < (lhs: BigNum, rhs: BigNum) -> Bool {
        CBigNumBoringSSL_BN_equal_consttime(lhs.ctx, rhs.ctx) == -1
    }
}

extension BigNum: ExpressibleByIntegerLiteral {
    public typealias IntegerLiteralType = Int

    public convenience init(integerLiteral value: Int) {
        self.init(value)
    }
}

// MARK: Operations

extension BigNum {
    static func operation(_ block: (_ result: BigNum) -> Int32) -> BigNum {
        let result = BigNum()
        precondition(block(result) == 1)
        return result
    }

    static func operationWithCtx(_ block: (BigNum, OpaquePointer?) -> Int32) -> BigNum {
        let result = BigNum()
        let context = CBigNumBoringSSL_BN_CTX_new()
        precondition(block(result, context) == 1)
        CBigNumBoringSSL_BN_CTX_free(context)
        return result
    }
}

public func + (lhs: BigNum, rhs: BigNum) -> BigNum {
    BigNum.operation {
        CBigNumBoringSSL_BN_add($0.ctx, lhs.ctx, rhs.ctx)
    }
}

public func - (lhs: BigNum, rhs: BigNum) -> BigNum {
    BigNum.operation {
        CBigNumBoringSSL_BN_sub($0.ctx, lhs.ctx, rhs.ctx)
    }
}

public func * (lhs: BigNum, rhs: BigNum) -> BigNum {
    BigNum.operationWithCtx {
        CBigNumBoringSSL_BN_mul($0.ctx, lhs.ctx, rhs.ctx, $1)
    }
}

/// Returns lhs / rhs, rounded to zero.
public func / (lhs: BigNum, rhs: BigNum) -> BigNum {
    BigNum.operationWithCtx {
        CBigNumBoringSSL_BN_div($0.ctx, nil, lhs.ctx, rhs.ctx, $1)
    }
}

/// Returns lhs / rhs, rounded to zero.
public func % (lhs: BigNum, rhs: BigNum) -> BigNum {
    BigNum.operationWithCtx {
        CBigNumBoringSSL_BN_div(nil, $0.ctx, lhs.ctx, rhs.ctx, $1)
    }
}

/// right shift
public func >> (lhs: BigNum, shift: Int32) -> BigNum {
    BigNum.operation {
        CBigNumBoringSSL_BN_rshift($0.ctx, lhs.ctx, shift)
    }
}

/// left shift
public func << (lhs: BigNum, shift: Int32) -> BigNum {
    BigNum.operation {
        CBigNumBoringSSL_BN_lshift($0.ctx, lhs.ctx, shift)
    }
}

// MARK: Member Operations

extension BigNum {
    public static func += (lhs: inout BigNum, rhs: BigNum) {
        lhs = BigNum.operation {
            CBigNumBoringSSL_BN_add($0.ctx, lhs.ctx, rhs.ctx)
        }
    }

    public static func -= (lhs: inout BigNum, rhs: BigNum) {
        lhs = BigNum.operation {
            CBigNumBoringSSL_BN_sub($0.ctx, lhs.ctx, rhs.ctx)
        }
    }

    public static func *= (lhs: inout BigNum, rhs: BigNum) {
        lhs = BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_mul($0.ctx, lhs.ctx, rhs.ctx, $1)
        }
    }

    public static func /= (lhs: inout BigNum, rhs: BigNum) {
        lhs = BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_div(
                $0.ctx,
                nil,
                lhs.ctx,
                rhs.ctx,
                $1
            )
        }
    }

    public static func %= (lhs: inout BigNum, rhs: BigNum) {
        lhs = BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_div(
                nil,
                $0.ctx,
                lhs.ctx,
                rhs.ctx,
                $1
            )
        }
    }

    /// Returns: (self ** 2)
    public func sqr() -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_sqr($0.ctx, self.ctx, $1)
        }
    }

    /// Returns: (self ** p)
    public func power(_ p: BigNum) -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_exp($0.ctx, self.ctx, p.ctx, $1)
        }
    }

    /// Returns: (self + b) % N
    public func add(_ b: BigNum, modulus: BigNum) -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_mod_add(
                $0.ctx,
                self.ctx,
                b.ctx,
                modulus.ctx,
                $1
            )
        }
    }

    /// Returns: (a - b) % N
    public func sub(_ b: BigNum, modulus: BigNum) -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_mod_sub(
                $0.ctx,
                self.ctx,
                b.ctx,
                modulus.ctx,
                $1
            )
        }
    }

    /// Returns: (a * b) % N
    public func mul(_ b: BigNum, modulus: BigNum) -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_mod_mul(
                $0.ctx,
                self.ctx,
                b.ctx,
                modulus.ctx,
                $1
            )
        }
    }

    /// Returns: (a ** 2) % N
    public func sqr(modulus: BigNum) -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_mod_sqr(
                $0.ctx,
                self.ctx,
                modulus.ctx,
                $1
            )
        }
    }

    /// Returns: (a ** p) % N
    public func power(_ p: BigNum, modulus: BigNum) -> BigNum {
        BigNum.operationWithCtx {
            CBigNumBoringSSL_BN_mod_exp(
                $0.ctx,
                self.ctx,
                p.ctx,
                modulus.ctx,
                $1
            )
        }
    }

    /// Return greatest common denominator
    public static func gcd(_ first: BigNum, _ second: BigNum) -> BigNum {
        self.operationWithCtx {
            CBigNumBoringSSL_BN_gcd(
                $0.ctx,
                first.ctx,
                second.ctx,
                $1
            )
        }
    }

    /// Bitwise operations

    public func setBit(_ bit: Int32) {
        CBigNumBoringSSL_BN_set_bit(self.ctx, bit)
    }

    public func clearBit(_ bit: Int32) {
        CBigNumBoringSSL_BN_clear_bit(self.ctx, bit)
    }

    public func mask(_ bits: Int32) {
        CBigNumBoringSSL_BN_mask_bits(self.ctx, bits)
    }

    public func isBitSet(_ bit: Int32) -> Bool {
        let set = CBigNumBoringSSL_BN_is_bit_set(self.ctx, bit)
        return set == 1 ? true : false
    }

    public func numBits() -> UInt32 {
        CBigNumBoringSSL_BN_num_bits(self.ctx)
    }

    /// random number generators

    public enum Top: Int32 {
        case any = -1
        case topBitSetToOne = 0
        case topTwoBitsSetToOne = 1
    }

    /// return cryptographically strong random number of maximum size defined in bits. random needs seeding prior to be called
    public static func random(bits: Int32, top: Top = .any, odd: Bool = false) -> BigNum {
        self.operation {
            CBigNumBoringSSL_BN_rand($0.ctx, bits, top.rawValue, odd ? 1 : 0)
        }
    }

    /// return pseudo random number of maximum size defined in bits.
    public static func psuedo_random(bits: Int32, top: Top = .any, odd: Bool = false) -> BigNum {
        self.operation {
            CBigNumBoringSSL_BN_pseudo_rand($0.ctx, bits, top.rawValue, odd ? 1 : 0)
        }
    }

    /// return cryptographically strong random number in range (0...max-1). random needs seeding prior to be called
    public static func random(max: BigNum) -> BigNum {
        self.operation {
            CBigNumBoringSSL_BN_rand_range($0.ctx, max.ctx)
        }
    }

    /// return pseudo random number in range (0..<max)
    public static func psuedo_random(max: BigNum) -> BigNum {
        self.operation {
            CBigNumBoringSSL_BN_pseudo_rand_range($0.ctx, max.ctx)
        }
    }

    /// prime number generator
    public static func generatePrime(
        bitSize: Int32,
        safe: Bool,
        add: BigNum? = nil,
        remainder: BigNum? = nil
    ) -> BigNum {
        self.operation {
            CBigNumBoringSSL_BN_generate_prime_ex(
                $0.ctx,
                bitSize,
                safe ? 1 : 0,
                add?.ctx,
                remainder?.ctx,
                nil
            )
        }
    }

    /// prime number generator
    public func isPrime(numChecks: Int32) -> Bool {
        let context = CBigNumBoringSSL_BN_CTX_new()
        defer {
            CBigNumBoringSSL_BN_CTX_free(context)
        }
        return CBigNumBoringSSL_BN_is_prime_ex(self.ctx, numChecks, context, nil) == 1
    }
}

/// TODO: Remove this when we move to the next major version
extension BigNum: @unchecked Sendable {}
