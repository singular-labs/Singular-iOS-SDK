Pod::Spec.new do |spec|
  spec.name         = "Singular"
  spec.version      = "9.2.4"
  spec.summary      = "Singular's iOS SDK"
  spec.description  = "Singular's SDK integration for iOS"
  spec.license      = "MIT"
  spec.homepage     = "https://www.singular.net/"
  spec.author       = "Singular Labs"
  spec.source       = { :git => "https://github.com/singular-labs/Singular-iOS-SDK.git", :tag => spec.version.to_s }

  spec.static_framework = true
  spec.ios.deployment_target = "8.0"
  spec.ios.source_files  = 'headers/*.{h,js}'
  spec.ios.vendored_library = 'libraries/libSingular.a' 
  spec.ios.frameworks  = ['AdSupport', 'Security', 'SystemConfiguration', 'iAd']
  spec.ios.libraries = ['sqlite3.0', 'z']
  spec.ios.pod_target_xcconfig = {
    'LIBRARY_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/Singular/**',
    'OTHER_LDFLAGS' => '$(inherited) -l"Singular"'
  }

end
