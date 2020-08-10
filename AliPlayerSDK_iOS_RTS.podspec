Pod::Spec.new do |s|
  s.name         = "AliPlayerSDK_iOS_RTS"
  s.version      = "4.7.5"
  s.summary      = "AliPlayerSDK_iOS_RTS."
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliPlayerSDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliPlayerSDK.git", :tag => "#{s.version}" }
	

  s.subspec 'AliPlayerSDK' do |playerSDK|
	playerSDK.vendored_frameworks = 'AliyunPlayer.framework','alivcffmpeg.framework','AlivcConan.framework','AliyunMediaDownloader.framework','artpSource.framework'
	playerSDK.frameworks = 'MediaPlayer','CoreGraphics','QuartzCore','CoreVideo','OpenGLES','AVFoundation','CoreMedia','VideoToolbox','AudioToolbox'
  end	
   
  #s.frameworks = 'VideoToolBox','MediaPlayer'
  #s.libraries = 'z'  
  s.requires_arc = true
   

end
