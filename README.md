# KindredSDK pod Setup

## Step 1: Install CocoaPods**

To install CocoaPods(if not already installed), open Terminal app and run the following command:

 ```$ sudo gem install cocoapods```
 
## Step 2: Create a Podfile**

In Terminal app, navigate to your Project folder and create a Podfile using

 ```$ touch Podfile```
 
Open the Podfile 

```open -e Podfile``` 

It will open the Podfile in TextEdit app. Copy and paste the following lines
```
source 'https://github.com/kindred-app/Specs.git'

target 'your_app_name' do
    pod 'KindredSDK', '1.7.1'
end

target 'your_keyboard_target' do
    pod 'KindredSDK', '1.7.1'
end
``` 

If you want to install only the Core SDK, then copy the following lines
```
source 'https://github.com/kindred-app/Specs.git'

target 'your_app_name' do
    pod 'KindredSDK/Core', '1.7.1'
end
``` 

Finally install the pod

```pod install```

## License
All rights reserved to Kindred.
