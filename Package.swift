// swift-tools-version: 5.7

import PackageDescription

let package = Package(
    name: "BlinkEReceiptStatic",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "BlinkEReceiptStatic",
            targets: ["BlinkEReceiptStatic"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "BlinkEReceiptStatic",
            url: "https://github.com/BlinkReceipt/blinkereceipt-ios/releases/download/2.26.1/BlinkEReceiptStatic.xcframework-2.26.1.zip",
            checksum: "cd58a039db66a6a3d90a668a8484cb6e87ee886d6ec62a82f8707bc6f9eb24fb"
        )
    ]
)
