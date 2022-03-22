Pod::Spec.new do |s|
   s.name = 'KindredSDK'
   s.version = '1.5.2-beta.0'
   s.license = 'KINDRED'
   s.summary = 'Kindred Keyboard SDK'
   s.homepage = 'https://www.kindredsdk.com'
   s.authors = 'Kindred Ltd'
   s.swift_version = "5"

   s.source = { :git => 'https://github.com/kindred-app/KindredSDK-Pod.git', :tag => s.version }
   s.platform = :ios, '11.0'
   s.module_name = 'KindredSDK'
   s.ios.deployment_target = '11.0'
   s.preserve_paths = 'Localizations/**/*.*'
   s.resources = ['Assets/**/*']
   s.resource_bundle = {
      'KindredSDKModule' => 'Localizations/*.lproj'
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

   def s.post_install(target)
   puts "\nGenerating KindredSDK resources bundle\n".yellow if config.verbose?
   Dir.chdir File.join(config.project_pods_root, 'KindredSDK') do
     command = "xcodebuild -project KindredSDK.xcodeproj -target KindredSDKBundle CONFIGURATION_BUILD_DIR=../Resources"
     command << " 2>&1 > /dev/null" unless config.verbose?
     unless system(command)
       raise ::Pod::Informative, "Failed to generate KindredSDK resources bundle"
     end

     File.open(File.join(config.project_pods_root, target.target_definition.copy_resources_script_name), 'a') do |file|
       file.puts "install_resource 'Resources/KindredSDKBundle.bundle'"
     end
   end
  end
end
