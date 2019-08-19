
pod spec lint AliPlayerPartSDK_iOS.podspec --verbose
pod trunk push AliPlayerPartSDK_iOS.podspec

pod spec lint AliPlayerSDK_iOS_RTS.podspec --verbose
pod trunk push AliPlayerSDK_iOS_RTS.podspec

pod spec lint AliPlayerPartSDK_iOS_RTS.podspec --verbose
pod trunk push AliPlayerPartSDK_iOS_RTS.podspec


pod spec lint AliPlayerSDK_iOS.podspec --verbose
pod trunk push AliPlayerSDK_iOS.podspec

