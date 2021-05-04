# KindredSDK - How to create XCFramework from KindredSDK


Here we are going to see the steps how to create pod spec project for Kindred SDK with its version. 


## Kindred SDK XCFramework

We need to create XCFramework from Kindred SDK repository. Please follow the steps to create XCFramework.

1.	Checkout Kindred SDK repository using this URL :- https://github.com/kindred-app/kindredui-keyboardsdk-ios.git
2.	Navigate to KindredSDK.xcodeproj and follow below steps: -

First, we need to create SDK archive using this command 
```bash
xcodebuild archive \
-scheme KindredSDK \
-configuration Release \
-destination 'generic/platform=iOS Simulator,name=iPhone 12 mini' \
-archivePath './build/KindredSDK.framework-iphoneos.xcarchive' \
SKIP_INSTALL=NO \
BUILD_LIBRARIES_FOR_DISTRIBUTION=YES
```

Second, we need to create XCFramweork using this command
```bash
xcrun xcodebuild -create-xcframework \
-framework './build/KindredSDK.framework-iphoneos.xcarchive/Products/Library/Frameworks/KindredSDK.framework' \
-output './build/KindredSDK.xcframework'
```

3.	If both commands successfully created you can see XCFramework file under project build folder as you can see in below screenshot: -
4.	Now create new repository and under that repository create Framework. 
5.	Copy KindredSDK XCFramework and other four frameworks that you can find under Frameworks folder as you can see in below screenshot. Its will be look like this:-
6.	Now create podspec file on outside of above framework folder: -
7.	Paste following inside KindredSDK.podspec file :-

```bash
Pod::Spec.new do |s|
   s.name = 'KindredSDK'
   s.version = '1.0.0'
   s.license = 'MIT'
   s.summary = 'TODO'
   s.homepage = 'http://kindred.com'
   s.authors = 'Kindred Ltd'
   s.source = { :git => 'https://github.com/kindred-app/KindredSDK-Pod.git', :tag => s.version }

   s.platform = :ios, '11.0'
   s.module_name = 'KindredSDK'
   s.ios.deployment_target = '11.0'	   
   s.ios.vendored_frameworks = 'Frameworks/FleksyApps.xcframework', 'Frameworks/KindredSDK.xcframework', 'Frameworks/FleksyEngine.xcframework', 'Frameworks/FleksyKeyboardSDK.xcframework', 'Frameworks/ServiceFramework.xcframework'
   s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
   s.requires_arc = true
end
```

8.	Now commit and push it to remote masters. 
9.	Open terminal and run the following command:-
```bash
pod repo add NEW_REPO_NAME URL_TO_NEW_REPO –allow-warnings
```
**THIS IS NEW REPO THAT WE CREATED IN STEP 4.**

10. Now run this command:
```bash
cd ~/.cocoapods/repos/NEW_REPO_NAME
```
11. Verify the repo using this command:
```bash
pod repo lint .
```
12.	Now we need to run the following command:
```bash
pod repo push Kindred SPEC_NAME.podspec (this is path to your podspec file in new repo)
```
13.	After running this command, it will create pod for Kindred SDK. 
14.	To test you can create empty project with pod and inside pod we can mention Kindred SDK like this

```bash
source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/kindred-app/sd-pod-test.git'
use_frameworks!
inhibit_all_warnings!

platform :ios, '13.0'

target 'Sample' do
    pod 'KindredSDK'
end
```


## License
[MIT](https://choosealicense.com/licenses/mit/)
