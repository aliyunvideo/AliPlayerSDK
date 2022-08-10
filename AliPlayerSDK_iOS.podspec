Pod::Spec.new do |s|
  s.name         = "AliPlayerSDK_iOS"
  s.version      = "5.4.6.0-25587639"
  s.summary      = "AliPlayerSDK_iOS."
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliPlayerSDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliPlayerSDK.git", :tag => "#{s.version}" }
  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }	

  s.subspec 'AliPlayerSDK' do |playerSDK|
	playerSDK.vendored_frameworks = 'AliyunPlayer.framework','alivcffmpeg.framework','AliyunMediaDownloader.framework'
	playerSDK.frameworks = 'MediaPlayer','CoreGraphics','QuartzCore','CoreVideo','OpenGLES','AVFoundation','CoreMedia','VideoToolbox','AudioToolbox'
  end	
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  #s.libraries = 'z'  
  s.requires_arc = true
   

end
