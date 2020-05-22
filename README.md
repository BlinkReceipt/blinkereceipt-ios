# BlinkEReceipt Integration Instructions

This is a framework which extends the [BlinkReceipt SDK](https://github.com/BlinkReceipt/blinkreceipt-ios) to enable e-receipt parsing functionality

## Installation with CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries like BlinkReceipt in your projects. If you do not have Cocoapods installed, see the [Getting Started Guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

### Podfile

```ruby
source 'https://github.com/BlinkReceipt/PodSpecRepo.git'
source 'https://github.com/CocoaPods/Specs.git'

platform :ios, '8.0'

target 'YourTarget' do
  use_frameworks!

  pod 'BlinkEReceipt'
end
```

After editing your Podfile, run `pod install` and then make sure to open the `.xcworkspace` file rather than the `.xcodeproj`

## Installation with Carthage

[Carthage](https://github.com/Carthage/Carthage) is a lightweight dependency manager for iOS. If you do not have Carthage installed see the [Quick Start](https://github.com/Carthage/Carthage#quick-start)

### Cartfile
```
binary "https://raw.githubusercontent.com/BlinkReceipt/blinkereceipt-ios/master/BlinkEReceiptStatic.json" ~> 1.0
```

After editing your `Cartfile`, run `carthage update` and then add the framework to your project as described in the Quick Start above

## Integration

- In order to use Amazon order parsing functionality add the following header:

```obj-c
#import <BlinkEReceipt/BRAmazonManager.h>
```

- It is recommended to instantiate the `BRAmazonManager` as early as possible to give it time to download the most recent Amazon parsing specs. Add the following line to your application delegate's `didFinishLaunchingWithOptions:` method:

```obj-c
[BRAmazonManager shared];
```

- In order to use email receipt parsing functionality add the following header:

```obj-c
#import <BlinkEReceipt/BREReceiptManager.h>
```

## Documentation

Please see our documentation at https://blinkreceipt.github.io/blinkereceipt-ios

Copyright (c) 2020 BlinkReceipt. All rights reserved.
