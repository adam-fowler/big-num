import CBigNum
import Foundation

public final class BigNum {
    internal let ctx: UnsafeMutablePointer<BIGNUM>

    public init(_ int: Int) {
        var ctx: UnsafeMutablePointer<BIGNUM>? = nil
        
        withUnsafePointer(to: int.bigEndian) { bytes in
            let raw = UnsafeRawPointer(bytes)
            let p = raw.bindMemory(to: UInt8.self, capacity: Int.bitWidth/8)
            ctx = BN_bin2bn(p, Int32(Int.bitWidth/8), nil)
        }
        self.ctx = ctx!
    }

    public init() {
        ctx = BN_new()
    }
    
    public init(_ dec: String) {
        var ctx: UnsafeMutablePointer<BIGNUM>? = nil
        BN_dec2bn(&ctx, dec)
        self.ctx = ctx!
    }

    public init(hex: String) {
        var ctx: UnsafeMutablePointer<BIGNUM>? = nil
        BN_hex2bn(&ctx, hex)
        self.ctx = ctx!
    }

    public convenience init(data: Data) {
        self.init()
        _ = data.withUnsafeBytes { bytes in
            let p = bytes.bindMemory(to: UInt8.self)
            BN_bin2bn(p.baseAddress, Int32(data.count), ctx)
        }
    }

    deinit {
        BN_free(ctx)
    }

    public var data: Data {
        var data = Data(count: Int((BN_num_bits(ctx) + 7) / 8))
        _ = data.withUnsafeMutableBytes { bytes in
            let p = bytes.bindMemory(to: UInt8.self)
            BN_bn2bin(ctx, p.baseAddress)
        }
        return data
    }

    public var dec: String {
        return String(validatingUTF8: BN_bn2dec(ctx))!
    }

    public var hex: String {
        return String(validatingUTF8: BN_bn2hex(ctx))!
    }
}

extension BigNum: CustomStringConvertible {
    public var description: String {
        return dec
    }
}

extension BigNum: Comparable {
    public static func == (lhs: BigNum, rhs: BigNum) -> Bool {
        return BN_cmp(lhs.ctx, rhs.ctx) == 0
    }

    public static func < (lhs: BigNum, rhs: BigNum) -> Bool {
        return BN_cmp(lhs.ctx, rhs.ctx) == -1
    }
}

//MARK: Operations

func operation(_ block: (_ result: BigNum) -> Int32) -> BigNum {
    let result = BigNum()
    precondition(block(result) == 1)
    return result
}

func operationWithCtx(_ block: (BigNum, OpaquePointer?) -> Int32) -> BigNum {
    let result = BigNum()
    let context = BN_CTX_new()
    precondition(block(result, context) == 1)
    BN_CTX_free(context)
    return result
}

public func + (lhs: BigNum, rhs: BigNum) -> BigNum {
    return operation {
        BN_add($0.ctx, lhs.ctx, rhs.ctx)
    }
}

public func - (lhs: BigNum, rhs: BigNum) -> BigNum {
    return operation {
        BN_sub($0.ctx, lhs.ctx, rhs.ctx)
    }
}

public func * (lhs: BigNum, rhs: BigNum) -> BigNum {
    return operationWithCtx {
        BN_mul($0.ctx, lhs.ctx, rhs.ctx, $1)
    }
}

/// Returns lhs / rhs, rounded to zero.
public func / (lhs: BigNum, rhs: BigNum) -> BigNum {
    return operationWithCtx {
        BN_div($0.ctx, nil, lhs.ctx, rhs.ctx, $1)
    }
}

/// Returns lhs / rhs, rounded to zero.
public func % (lhs: BigNum, rhs: BigNum) -> BigNum {
    return operationWithCtx {
        BN_div(nil, $0.ctx, lhs.ctx, rhs.ctx, $1)
    }
}

//MARK: Member Operations

public extension BigNum {

    /// Returns: (self ** 2)
    func sqr() -> BigNum {
        return operationWithCtx {
            BN_sqr($0.ctx, self.ctx, $1)
        }
    }

    /// Returns: (self ** p)
    func power(_ p: BigNum) -> BigNum {
        return operationWithCtx {
            BN_exp($0.ctx, self.ctx, p.ctx, $1)
        }
    }
    
    /// Returns: (self + b) % N
    func add(_ b: BigNum, modulus: BigNum) -> BigNum {
        return operationWithCtx {
            BN_mod_add($0.ctx, self.ctx, b.ctx, modulus.ctx, $1)
        }
    }

    /// Returns: (a - b) % N
    func sub(_ b: BigNum, modulus: BigNum) -> BigNum {
        return operationWithCtx {
            BN_mod_sub($0.ctx, self.ctx, b.ctx, modulus.ctx, $1)
        }
    }

    /// Returns: (a * b) % N
    func mul(_ b: BigNum, modulus: BigNum) -> BigNum {
        return operationWithCtx {
            BN_mod_mul($0.ctx, self.ctx, b.ctx, modulus.ctx, $1)
        }
    }

    /// Returns: (a ** 2) % N
    func sqr(modulus: BigNum) -> BigNum {
        return operationWithCtx {
            BN_mod_sqr($0.ctx, self.ctx, modulus.ctx, $1)
        }
    }

    /// Returns: (a ** p) % N
    func power(_ p: BigNum, modulus: BigNum) -> BigNum {
        return operationWithCtx {
            BN_mod_exp($0.ctx, self.ctx, p.ctx, modulus.ctx, $1)
        }
    }
}
