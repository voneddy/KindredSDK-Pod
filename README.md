# KindredSDK Setup


**If your poroject does't have pods then we need to setup pods first by using below steps:-**

1. Open Terminal and execute: 
2. ```bash $ sudo gem install cocoapods```
3. Navigate to your Project folder (I assume in your case it's cd /Users/myName/Developer/SimpleWeather/SimpleWeather.xcodeproj).
4. bash Setup Cocoapod pod setup
5. Create the Podfile touch Podfile
6. Open the Podfile open -e Podfile and insert your code for Podfile
7. Finally install the Podfile pod install


Once pods are setup you can past the followign code into your Podfile

```bash
source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/kindred-app/Specs.git'
use_frameworks!
inhibit_all_warnings!

platform :ios, '11.0'

target '**Sample**' do
    pod 'KindredSDK'
end
```




## License
[MIT](https://choosealicense.com/licenses/mit/)
Kindred Ltd - All rights reserved.
