Pod::Spec.new do |spec|
spec.name         = "OpenADAdsSDK10"
spec.version      = "0.0.1"
spec.summary      = "OpenAd三方广告平台"
spec.description  = <<-DESC
OpenAd三方广告平台
DESC
spec.homepage     = "https://github.com/konnitiha/OpenADAdsSDK10.git"
spec.license      = { :type => "MIT", :file => "LICENSE" }
spec.author             = { "openad" => "1053591151@qq.com" }
spec.source       = { :git => "https://github.com/konnitiha/OpenADAdsSDK10.git", :tag => spec.version }
spec.platform     = :ios, '12.0'
spec.ios.deployment_target = '12.0'
spec.requires_arc = true
spec.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "Security", "SystemConfiguration", "CoreTelephony", "AdSupport", "WebKit", "Accelerate", "CoreMotion","StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia","CoreLocation", "AVKit","CoreGraphics","CoreImage","AudioToolbox"]

spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC'],'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
spec.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi", "resolv"]
valid_archs = ['x86_64', 'arm64']
spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 arm64' }
spec.default_subspecs = 'OpenADAdsSDK10'

spec.subspec 'OpenADAdsSDK10' do |ss|
     ss.ios.deployment_target = '12.0'
     ss.vendored_frameworks = 'BBTAds.xcframework'
     ss.resources = ['BBTAds.xcframework/ios-arm64/BBTAds.framework/BBTAdsResources.bundle']
     
  end

end
