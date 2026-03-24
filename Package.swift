// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Singular",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "Singular",
            targets: ["Singular"]),
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "SingularBinary",
            path: "Singular.xcframework"
        ),
        .target(
            name: "Singular",
            dependencies: ["SingularBinary"],
            linkerSettings: [
                .linkedFramework("StoreKit"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("AdSupport"),
                .linkedFramework("Security"),
                .linkedFramework("WebKit"),
                .linkedLibrary("sqlite3.0"),
                .linkedLibrary("z")
            ]
        )
    ]
)
