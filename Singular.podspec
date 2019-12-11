Pod::Spec.new do |spec|
  spec.name         = "Singular"
  spec.version      = "9.2.3"
  spec.summary      = "Singular's iOS SDK"
  spec.description  = "Singular's SDK integration for iOS"
  spec.license      = "MIT"

  spec.homepage     = "https://www.singular.net/"

  spec.author       = "Singular Labs"

  spec.ios.deployment_target = "8.0"
  spec.source       = { :git => "https://github.com/singular-labs/Singular-iOS-SDK.git", :tag => spec.version.to_s }

  spec.source_files  = "Singular.h", "SingularLinkParams.h", "Singular.js"
  spec.vendored_library = 'libSingular.a' 

  spec.frameworks  = ['AdSupport', 'Security', 'SystemConfiguration', 'iAd']
  spec.libraries = ['sqlite3.0', 'z']

  spec.ios.pod_target_xcconfig = {
    'LIBRARY_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/Singular/**',
    'OTHER_LDFLAGS' => '$(inherited) -l"Singular"'
  }

end
