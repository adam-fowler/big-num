import Foundation
import Testing

@testable import BigNum

struct BigNumTests {
    @Test func testConversion() {
        #expect(BigNum(14_887_387_467_384) == BigNum("14887387467384"))
        #expect(BigNum("92") == BigNum(hex: "5c"))
    }

    @Test func testDataConversion() {
        let number = BigNum(14_887_387_467_384)
        let data = number.data
        let bytes = number.bytes
        let hex = number.hex
        let dec = number.dec
        #expect(BigNum(14_887_387_467_384) == BigNum("14887387467384"))
        #expect(BigNum("92") == BigNum(hex: "5c"))
        #expect(BigNum(bytes: data) == number)
        #expect(BigNum(bytes: bytes) == number)
        #expect(BigNum(hex: hex) == number)
        #expect(BigNum(dec) == number)
    }

    @Test func testBasic() {
        let a = BigNum(13)
        let b = BigNum(105)
        let c = a + b
        #expect(c == 118)
    }

    @Test func testAdd() {
        var a = BigNum(132_435_353_453)
        let b = BigNum(23_453_532_535)
        let c = a + b
        #expect(c == BigNum(132_435_353_453 + 23_453_532_535))

        a += b
        #expect(c == a)
    }

    @Test func testSubtract() {
        var a = BigNum(132_435_987_897_453)
        let b = BigNum(23_453_532_535)
        let c = a - b
        #expect(c == BigNum(132_435_987_897_453 - 23_453_532_535))

        a -= b
        #expect(c == a)
    }

    @Test func testMultiple() {
        var a = BigNum(45)
        let b = BigNum(23_453_532_535)
        let c = a * b
        #expect(c == BigNum(45 * 23_453_532_535))

        a *= b
        #expect(c == a)
    }

    @Test func testDivide() {
        var a = BigNum(487_380_435_867_034_585)
        let b = BigNum(23_453_532_535)
        let c = a / b
        #expect(c == BigNum(487_380_435_867_034_585 / 23_453_532_535))

        a /= b
        #expect(c == a)
    }

    @Test func testModulus() {
        var a = BigNum(487_380_435_867_034_585)
        let b = BigNum(23_453_532_535)
        let c = a % b
        #expect(c == BigNum(487_380_435_867_034_585 % 23_453_532_535))

        a %= b
        #expect(c == a)
    }

    @Test func testSquare() {
        let a = BigNum(487_034_585)
        let c = a * a
        #expect(c == BigNum(487_034_585 * 487_034_585))
    }

    @Test func testPower() {
        let a = BigNum(45)
        let b = BigNum(6)
        let c = a.power(b)
        #expect(c == BigNum(Int(pow(Double(45), Double(6)))))
    }

    @Test func testModAdd() {
        let N = BigNum(87_178_291_199)
        let a = BigNum(28_868_624_873)
        let b = BigNum(28_333_868_624_873)
        let c = a.add(b, modulus: N)
        #expect(c == BigNum((28_868_624_873 + 28_333_868_624_873) % 87_178_291_199))
    }

    @Test func testModSubtract() {
        let N = BigNum(87_178_291_199)
        let a = BigNum(28_333_868_624_873)
        let b = BigNum(28_868_624_873)
        let c = a.sub(b, modulus: N)
        #expect(c == BigNum((28_333_868_624_873 - 28_868_624_873) % 87_178_291_199))
    }

    @Test func testModMultiple() {
        let N = BigNum(87_178_291_199)
        let a = BigNum(67)
        let b = BigNum(28_876_783_243)
        let c = a.mul(b, modulus: N)
        #expect(c == BigNum((67 * 28_876_783_243) % 87_178_291_199))
    }

    @Test func testModSquare() {
        let N = BigNum(2_971_215_073)
        let a = BigNum(67647)
        let c = a.sqr(modulus: N)
        #expect(c == BigNum((67647 * 67647) % 2_971_215_073))
    }

    @Test func testModPower() {
        let N = BigNum(433_494_437)
        let a = BigNum(67)
        let b = BigNum(7)
        let c = a.power(b, modulus: N)
        #expect(c == BigNum(Int(pow(Double(67), Double(7))) % 433_494_437))
    }

    @Test func testLargeModPower() {
        let N = BigNum(
            hex:
                "FFFFFFFFFFFFFFFFC90FDAA22168C234C4C6628B80DC1CD1"
                + "29024E088A67CC74020BBEA63B139B22514A08798E3404DD"
                + "EF9519B3CD3A431B302B0A6DF25F14374FE1356D6D51C245"
                + "E485B576625E7EC6F44C42E9A637ED6B0BFF5CB6F406B7ED"
                + "EE386BFB5A899FA5AE9F24117C4B1FE649286651ECE45B3D"
                + "C2007CB8A163BF0598DA48361C55D39A69163FA8FD24CF5F"
                + "83655D23DCA3AD961C62F356208552BB9ED529077096966D"
                + "670C354E4ABC9804F1746C08CA18217C32905E462E36CE3B"
                + "E39E772C180E86039B2783A2EC07A28FB5C55DF06F4C52C9"
                + "DE2BCBF6955817183995497CEA956AE515D2261898FA0510"
                + "15728E5A8AAAC42DAD33170D04507A33A85521ABDF1CBA64"
                + "ECFB850458DBEF0A8AEA71575D060C7DB3970F85A6E1E4C7"
                + "ABF5AE8CDB0933D71E8C94E04A25619DCEE3D2261AD2EE6B"
                + "F12FFA06D98A0864D87602733EC86A64521F2B18177B200C"
                + "BBE117577A615D6C770988C0BAD946E208E24FA074E5AB31"
                + "43DB5BFCE0FD108E4B82D120A93AD2CAFFFFFFFFFFFFFFFF"
        )!
        let a = BigNum(
            hex:
                "37981750af33fdf93fc6dce831fe794aba312572e7c33472528"
                + "54e5ce7c7f40343f5ad82f9ad3585c8cb1184c54c562f8317fc"
                + "2924c6c7ade72f1e8d964f606e040c8f9f0b12e3fe6b6828202"
                + "a5e40ca0103e880531921e56de3acc410331b8e5ddcd0dbf249"
                + "bfa104f6b797719613aa50eabcdb40fd5457f64861dd71890eba"
        )!
        let expectedResult = BigNum(
            hex:
                "f93b917abccc667f4fac29d1e4c111bcd37d2c37577e7f113ad85030ec6"
                + "157c70dfee728ac4aee9a7631d85a68aec3ef72864b6e8a134f5c5eef89"
                + "40b93bb1db1ada9c1de770db282d644eeb3c551d35ce8de4d2cf98d0d79"
                + "9b6a7f1fe51568d11162ce0cded8246b630169dcfc2d5a43817d52f121b"
                + "3d75ab1a43dc30b7cec02e42e332d5fd781023d9c1fd44f3d1129d21155"
                + "0ce57c004aca95a367592705b517298f724e6314ffbac2425b2beb5095f"
                + "23b75dd3dd232adda700080d7a22a87383d3746d39f6427b7daf2a00683"
                + "038ff7dc099081b2bf43eb5e2e30465487dafb3cc875fdd9b475d46a0ac"
                + "1d07cf928fd11e06c5999596160168fc31228f7f3329d4b873acbf1540a"
                + "16418a3ee5a0a5070a3db558f5cf8cf15388ff0a6e4234bf1de3e5bade8"
                + "e4aa607d633a94a06bee4386c7444e06fd584282b9d576be318f0f20305"
                + "7e80996f79a2bb0a63ad4786d5cc12b1321bd6644e001cee194171f5b04"
                + "fcd65f3f280b6dadabae0401a9ae557ad27939730ce146319aa7f08d1e33"
        )!
        let g = BigNum(2)
        let A = g.power(a, modulus: N)
        #expect(A == expectedResult)
    }

    @Test func testGCD() {
        let a = BigNum(333)
        let b = BigNum(27)
        let gcd = BigNum.gcd(a, b)
        #expect(gcd == BigNum(9))
    }

    @Test func testLeftShift() {
        let a = BigNum(hex: "87237634a5fed7")!
        let b = a << 4
        #expect(b == BigNum(hex: "87237634a5fed70")!)
    }

    @Test func testRightShift() {
        let a = BigNum(hex: "87237634aed78dc90a5fed7")!
        let b = a >> 12
        #expect(b == BigNum(hex: "87237634aed78dc90a5f")!)
    }

    @Test func testNotHex() {
        let a = BigNum(hex: "sdf876sjhk")
        #expect(a == nil)
    }

    @Test func testRandom() {
        let r = BigNum.random(bits: 96, top: .topBitSetToOne)
        #expect(r.numBits() == 96)
        #expect(r.isBitSet(95))
    }

    @Test func testPrime() {
        let r = BigNum.generatePrime(bitSize: 128, safe: false)
        #expect(r.isPrime(numChecks: 128))
    }

    @Test func testFactorial() {
        var factorial = BigNum(1)
        for i in 1..<100 {
            factorial = factorial * BigNum(i)
        }
        for i in 1..<100 {
            #expect(BigNum.gcd(BigNum(i), factorial) == BigNum(i))
        }
    }
}
