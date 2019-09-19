//
//  AVPHlsKeyGenerator.h
//  AliPlayerSDK
//
//

#import <Foundation/Foundation.h>


@protocol AVPLiveKeyInfoDelegate <NSObject>

@required
/*
 功能：异步，获取到m3u8中的URI，解析出key，将key相关信息回调出去，如果有两个key，则会回调两次
 ekeyGenURL: 密文key的url
 ekeyPreGenTime:在多少时间内必须要生成key，这个时间可以用于打散，如果time=0，表示打散时间为0，这个key必须要优先立即生成
 */
/***
 Feature: Asynchronous key generation. Retrieve the URI from m3u8, parse the URI, generate a key, and then return the key information. If two keys are generated, two callbacks are required.
 ekeyGenURL: The URL of the ciphertext key.
 ekeyPreGenTime: The maximum key generation time. You can divide the time into multiple periods. If time=0, then the key must be generated immediately.
 */
-(void) onLiveKeyInfo:(NSString*)ekeyGenURL ekeyPreGenTime:(int)time;

/*
 功能：同步，通过密文key来获取到明文key
 ekeyGenURL: 密文key的url
 */
/***
 Feature: Synchronous key generation. Use a ciphertext key to generate a plaintext key.
 ekeyGenURL: The URL of the ciphertext key.
 */
-(NSData*) onGetLiveKey:(NSString*)ekeyGenURL;

@end

OBJC_EXPORT
@interface AVPLiveKeyGenerator : NSObject

+ (AVPLiveKeyGenerator *) getInstance;

@property(nonatomic,weak) id<AVPLiveKeyInfoDelegate> delegate;

@end
