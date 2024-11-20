Pod::Spec.new do |spec|
  spec.name         = "Singular-SDK"
  spec.version      = "12.6.1"
  spec.summary      = "Singular's iOS SDK"
  spec.description  = "Singular's SDK integration for iOS"
  spec.license      = "MIT"
  spec.homepage     = "https://www.singular.net/"
  spec.author       = "Singular Labs"
  spec.source       = { :git => "https://github.com/singular-labs/Singular-iOS-SDK.git", :tag => spec.version.to_s }

  spec.static_framework = true

  spec.ios.deployment_target = "12.0"
  spec.ios.frameworks  = 'AdSupport', 'Security', 'SystemConfiguration', 'StoreKit', 'WebKit'
  spec.ios.weak_framework = 'AdServices'

  spec.ios.libraries = 'sqlite3.0', 'z'

  spec.default_subspecs = 'Main'

  spec.subspec 'Main' do |ss|
    ss.ios.vendored_frameworks = 'Singular.xcframework'
    ss.resource_bundles = {'Singular' => ['frameworks/Singular.framework/PrivacyInfo.xcprivacy']}
  end
  
  spec.subspec 'Legacy' do |ss|
    ss.ios.vendored_frameworks = 'frameworks/Singular.framework'
    ss.ios.source_files  = 'headers/*.h'
    ss.ios.resources = ['headers/*.js']

    ss.pod_target_xcconfig = {
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    }
    ss.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    ss.ios.pod_target_xcconfig = {
        'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/Singular-SDK/frameworks/**',
        'OTHER_LDFLAGS' => '$(inherited) -framework "Singular"'
  }
  end
end
