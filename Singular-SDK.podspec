Pod::Spec.new do |spec|
  spec.name         = "Singular-SDK"
  spec.version      = "9.4.2"
  spec.summary      = "Singular's iOS SDK"
  spec.description  = "Singular's SDK integration for iOS"
  spec.license      = "MIT"
  spec.homepage     = "https://www.singular.net/"
  spec.author       = "Singular Labs"
  spec.source       = { :git => "https://github.com/singular-labs/Singular-iOS-SDK.git", :tag => spec.version.to_s }

  spec.static_framework = true
  spec.ios.deployment_target = "8.0"
  spec.ios.source_files  = 'headers/*.h'
  spec.ios.resources = ['headers/*.js']
  spec.ios.vendored_frameworks = 'frameworks/Singular.framework' 
  spec.ios.frameworks  = 'AdSupport', 'Security', 'SystemConfiguration', 'iAd'
  spec.ios.libraries = 'sqlite3.0', 'z'
  spec.ios.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/Singular-SDK/frameworks/**',
    'OTHER_LDFLAGS' => '$(inherited) -framework "Singular"'
  }

end