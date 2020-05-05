// swift-tools-version:5.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "big-num",
    products: [
        // Products define the executables and libraries produced by a package, and make them visible to other packages.
        .library(name: "BigNum", targets: ["BigNum"]),
        /* This target is used only for symbol mangling. It's added and removed automatically because it emits build warnings. MANGLE_START
            .library(name: "CBigNumBoringSSL", type: .static, targets: ["CBigNumBoringSSL"]),
            MANGLE_END */
    ],
    dependencies: [],
    targets: [
        .target(name: "BigNum", dependencies: ["CBigNumBoringSSL"]),
        .target(name: "CBigNumBoringSSL"),
        .testTarget(name: "BigNumTests", dependencies: ["BigNum"]),
    ]
)
