import XCTest
@testable import BigNum

final class BigNumTests: XCTestCase {
    
    func testConversion() {
        XCTAssertEqual(BigNum(14887387467384), BigNum("14887387467384"))
        XCTAssertEqual(BigNum("92"), BigNum(hex:"5c"))
    }
    
    func testBasic() {
        let a = BigNum(13)
        let b = BigNum(105)
        let c = a + b
        XCTAssertEqual(c, BigNum(118))
    }

    func testAdd() {
        let a = BigNum(132435353453)
        let b = BigNum(23453532535)
        let c = a + b
        XCTAssertEqual(c, BigNum(132435353453+23453532535))
    }

    func testSubtract() {
        let a = BigNum(132435987897453)
        let b = BigNum(23453532535)
        let c = a - b
        XCTAssertEqual(c, BigNum(132435987897453-23453532535))
    }

    func testMultiple() {
        let a = BigNum(45)
        let b = BigNum(23453532535)
        let c = a * b
        XCTAssertEqual(c, BigNum(45*23453532535))
    }

    func testDivide() {
        let a = BigNum(487380435867034585)
        let b = BigNum(23453532535)
        let c = a / b
        XCTAssertEqual(c, BigNum(487380435867034585 / 23453532535))
    }

    func testModulus() {
        let a = BigNum(487380435867034585)
        let b = BigNum(23453532535)
        let c = a % b
        XCTAssertEqual(c, BigNum(487380435867034585 % 23453532535))
    }
    
    func testSquare() {
        let a = BigNum(487034585)
        let c = a * a
        XCTAssertEqual(c, BigNum(487034585 * 487034585))
    }

    func testPower() {
        let a = BigNum(45)
        let b = BigNum(6)
        let c = a.power(b)
        XCTAssertEqual(c, BigNum(Int(truncating: NSDecimalNumber(decimal: pow(45,6)))))
    }

    func testModAdd() {
        let N = BigNum(87178291199)
        let a = BigNum(28868624873)
        let b = BigNum(28333868624873)
        let c = a.add(b, modulus: N)
        XCTAssertEqual(c, BigNum((28868624873 + 28333868624873) % 87178291199))
    }
    
    func testModSubtract() {
        let N = BigNum(87178291199)
        let a = BigNum(28333868624873)
        let b = BigNum(28868624873)
        let c = a.sub(b, modulus: N)
        XCTAssertEqual(c, BigNum((28333868624873 - 28868624873) % 87178291199))
    }
    
    func testModMultiple() {
        let N = BigNum(87178291199)
        let a = BigNum(67)
        let b = BigNum(28876783243)
        let c = a.mul(b, modulus: N)
        XCTAssertEqual(c, BigNum((67 * 28876783243) % 87178291199))
    }
    
    func testModSquare() {
        let N = BigNum(2971215073)
        let a = BigNum(67647)
        let c = a.sqr(modulus:N)
        XCTAssertEqual(c, BigNum((67647 * 67647) % 2971215073))
    }
    
    func testModPower() {
        let N = BigNum(433494437)
        let a = BigNum(67)
        let b = BigNum(7)
        let c = a.power(b, modulus: N)
        XCTAssertEqual(c, BigNum(Int(truncating: NSDecimalNumber(decimal: pow(67,7))) % 433494437))
    }
    
    func testLargeModPower() {
        let N = BigNum(hex:
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
        )
        let a = BigNum(hex:
            "37981750af33fdf93fc6dce831fe794aba312572e7c33472528" +
            "54e5ce7c7f40343f5ad82f9ad3585c8cb1184c54c562f8317fc" +
            "2924c6c7ade72f1e8d964f606e040c8f9f0b12e3fe6b6828202" +
            "a5e40ca0103e880531921e56de3acc410331b8e5ddcd0dbf249" +
            "bfa104f6b797719613aa50eabcdb40fd5457f64861dd71890eba"
        )
        let expectedResult = BigNum(hex:
            "f93b917abccc667f4fac29d1e4c111bcd37d2c37577e7f113ad85030ec6" +
            "157c70dfee728ac4aee9a7631d85a68aec3ef72864b6e8a134f5c5eef89" +
            "40b93bb1db1ada9c1de770db282d644eeb3c551d35ce8de4d2cf98d0d79" +
            "9b6a7f1fe51568d11162ce0cded8246b630169dcfc2d5a43817d52f121b" +
            "3d75ab1a43dc30b7cec02e42e332d5fd781023d9c1fd44f3d1129d21155" +
            "0ce57c004aca95a367592705b517298f724e6314ffbac2425b2beb5095f" +
            "23b75dd3dd232adda700080d7a22a87383d3746d39f6427b7daf2a00683" +
            "038ff7dc099081b2bf43eb5e2e30465487dafb3cc875fdd9b475d46a0ac" +
            "1d07cf928fd11e06c5999596160168fc31228f7f3329d4b873acbf1540a" +
            "16418a3ee5a0a5070a3db558f5cf8cf15388ff0a6e4234bf1de3e5bade8" +
            "e4aa607d633a94a06bee4386c7444e06fd584282b9d576be318f0f20305" +
            "7e80996f79a2bb0a63ad4786d5cc12b1321bd6644e001cee194171f5b04" +
            "fcd65f3f280b6dadabae0401a9ae557ad27939730ce146319aa7f08d1e33"
        )
        let g = BigNum(2)
        let A = g.power(a, modulus: N)
        XCTAssertEqual(A, expectedResult)
    }
    
    static var allTests = [
        ("testConversion", testConversion),
        ("testBasic", testBasic),
        ("testAdd", testAdd),
        ("testSubtract", testSubtract),
        ("testMultiple", testMultiple),
        ("testDivide", testDivide),
        ("testModulus", testModulus),
        ("testSquare", testSquare),
        ("testPower", testPower),
        ("testModAdd", testModAdd),
        ("testModSubtract", testModSubtract),
        ("testModMultiple", testModMultiple),
        ("testModSquare", testModSquare),
        ("testModPower", testModPower),
        ("testLargeModPower", testLargeModPower),
    ]
}
