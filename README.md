# KindredSDK Setup


**If your poroject does't have pods then we need to setup pods first by using below steps:-**

1. Open Terminal and execute: $ sudo gem install cocoapods
2. Navigate to your Project folder (I assume in your case it's cd /Users/myName/Developer/SimpleWeather/SimpleWeather.xcodeproj).
3. Setup Cocoapod pod setup
4. Create the Podfile touch Podfile
5. Open the Podfile open -e Podfile and insert your code for Podfile
6. Finally install the Podfile pod install

Once pods are setup you can past the followign code into your Podfile

```bash
source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/kindred-app/sd-pod-test.git'
use_frameworks!
inhibit_all_warnings!

platform :ios, '13.0'

target '**Sample**' do
    pod 'KindredSDK'
end
```




## License
[MIT](https://choosealicense.com/licenses/mit/)
