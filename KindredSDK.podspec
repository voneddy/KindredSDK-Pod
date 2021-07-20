Pod::Spec.new do |s|
   s.name = 'KindredSDK'
   s.version = '1.0.4'
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
