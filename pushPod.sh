
pod spec lint AliPlayerPartSDK_iOS.podspec --verbose
pod trunk push AliPlayerPartSDK_iOS.podspec

pod spec lint AliPlayerSDK_iOS_ARTC.podspec --verbose
pod trunk push AliPlayerSDK_iOS_ARTC.podspec

# pod spec lint AliPlayerSDK_iOS_ARTP.podspec --verbose
# pod trunk push AliPlayerSDK_iOS_ARTP.podspec

pod spec lint AliPlayerSDK_iOS.podspec --verbose
pod trunk push AliPlayerSDK_iOS.podspec

