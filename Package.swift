// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "big-num",
    products: [
        // Products define the executables and libraries produced by a package, and make them visible to other packages.
        .library(name: "BigNum", targets: ["BigNum"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .target(name: "BigNum", dependencies: ["CBigNum"]),
        .target(name: "CBigNum", dependencies: ["CBigNumOpenSSL"]),
        .systemLibrary(
            name: "CBigNumOpenSSL",
            pkgConfig: "openssl",
            providers: [
                .apt(["openssl libssl-dev"]),
                .brew(["openssl"])
            ]
        ),
        .testTarget(name: "BigNumTests", dependencies: ["BigNum"]),
    ]
)
