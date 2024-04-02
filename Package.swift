// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Singular",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "Singular",
            targets: ["Singular"]),
    ],
    dependencies: [
    ],
    targets: [
        .target(
            name: "Singular",
            dependencies:["SingularBinary"],
            path: "Singular/",
            resources: [.copy("PrivacyInfo.xcprivacy")]),
        .binaryTarget(name: "SingularBinary", path: "Singular-SPM.xcframework")
    ]
)
