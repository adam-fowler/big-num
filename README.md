# BigNum

BigNum provides a wrapper for the OpenSSL BIGNUM library.

It provides most of the standard library functions
- Basic arithmetic operators (with and without modulus)
- Bitwise operators
- Powers (with and without modulus)
- Greatest common denominator
- Prime generation
- Random number generation

Below is a function that creates factorial 1000 and then verifies that for every number from 1 to 1000 the greatest common denominator between the variable `factorial` and that number is equal to that number.
```swift
        var factorial = BigNum(1)
        for i in 1..<1000 {
            factorial = factorial * BigNum(i)
        }
        for i in 1..<1000 {
            assert(BigNum.gcd(i, factorial) == i)
        }
```
