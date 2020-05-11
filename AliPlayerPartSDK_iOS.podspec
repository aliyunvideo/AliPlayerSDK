Pod::Spec.new do |s|
  s.name         = "AliPlayerPartSDK_iOS"
  s.version      = "5.1.2"
  s.summary      = "AliPlayerPartSDK_iOS."
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliPlayerSDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliPlayerSDK.git", :tag => "#{s.version}" }
	

  s.subspec 'AliPlayerPartSDK' do |playerSDK|
	playerSDK.vendored_frameworks = 'AliyunPlayer.framework','AliyunMediaDownloader.framework'
	playerSDK.frameworks = 'MediaPlayer','CoreGraphics','QuartzCore','CoreVideo','OpenGLES','AVFoundation','CoreMedia','VideoToolbox','AudioToolbox'
  end	
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  #s.libraries = 'z'  
  s.requires_arc = true
   

end
