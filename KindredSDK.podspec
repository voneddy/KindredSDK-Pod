Pod::Spec.new do |s|
   s.name = 'KindredSDK'
   s.version = '1.5.1-beta.7'
   s.license = 'KINDRED'
   s.summary = 'Kindred Keyboard SDK'
   s.homepage = 'https://www.kindredsdk.com'
   s.authors = 'Kindred Ltd'
   s.swift_version = "5"

   s.source = { :git => 'https://github.com/kindred-app/KindredSDK-Pod.git', :tag => s.version }
   s.platform = :ios, '11.0'
   s.module_name = 'KindredSDK'
   s.ios.deployment_target = '11.0'
   s.resources = ['Assets/**/*']
   s.resource_bundles = {
      'KindredSDKModule' => ['Pods/KindredSDK/Localizations/*.lproj/*.strings']
   }
   s.ios.vendored_frameworks = 'Frameworks/FleksyApps.xcframework', 'Frameworks/KindredSDK.xcframework', 'Frameworks/FleksyEngine.xcframework', 'Frameworks/FleksyKeyboardSDK.xcframework', 'Frameworks/ServiceFramework.xcframework', 'Frameworks/FleksyHelperSDK.xcframework'
   s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
   s.requires_arc = true

   s.subspec 'Core' do |core|
      core.ios.vendored_frameworks = 'Frameworks/KindredSDKCore.xcframework'
   end

   s.subspec 'KindredSDK' do |sdk|
      sdk.dependency 'KindredSDK/Core'
   end
end
