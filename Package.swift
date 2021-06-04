// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Singular",
    products: [
        .library(
            name: "Singular",
            targets: ["Singular"]),
    ],
    dependencies: [
    ],
    targets: [.binaryTarget(
                name: "Singular",
                path: "Singular.xcframework")]
)
