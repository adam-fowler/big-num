// swift-tools-version:6.1
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let defaultSwiftSettings: [SwiftSetting] =
    [
        // https://github.com/swiftlang/swift-evolution/blob/main/proposals/0409-access-level-on-imports.md
        .enableUpcomingFeature("InternalImportsByDefault"),

        // https://github.com/swiftlang/swift-evolution/blob/main/proposals/0444-member-import-visibility.md
        .enableUpcomingFeature("MemberImportVisibility"),
    ]

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
        .target(
            name: "BigNum",
            dependencies: ["CBigNumBoringSSL"],
            swiftSettings: defaultSwiftSettings
        ),
        .target(name: "CBigNumBoringSSL"),
        .testTarget(name: "BigNumTests", dependencies: ["BigNum"]),
    ],
    cxxLanguageStandard: .cxx17
)
