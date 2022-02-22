
#import <AliyunPlayer/AVPDef.h>
#import <Foundation/Foundation.h>

@class AVPMediaInfo;
@class AVPVidStsSource;
@class AVPVidAuthSource;


@protocol AliVodMediaLoaderStatusDelegate <NSObject>
@optional

/**
 @brief  准备完成
 */
- (void)onPrepared:(AVPMediaInfo *)mediaInfo;

/**
 @brief 错误回调
 @param url 加载url
 @param code 错误码
 @param msg 错误描述
 */
- (void)onError:(NSString *)vid index:(int)index code:(int64_t)code msg:(NSString *)msg;

/**
 @brief 完成回调
 @param url 加载url
 */
- (void)onCompleted:(NSString *)vid index:(int)index;

/**
 @brief 取消回调
 @param url 加载url
 */
- (void)onCanceled:(NSString *)vid index:(int)index;

@end


OBJC_EXPORT
@interface AliVodMediaLoader : NSObject

+ (instancetype)shareInstance;

- (void)prepareVidStsSource:(AVPVidStsSource *)stsSource;

- (void)prepareVidAuthSource:(AVPVidAuthSource *)authSource;

- (void)removeVidSource:(NSString *)vid;

/**
    @brief  开始加载文件。异步加载。可以同时加载多个。
     @param url  视频文件地址
     @param duration 加载的时长大小.单位：毫秒
    */
- (void)load:(NSString *)vid index:(int)index duration:(int64_t)duration;

/**
  @brief 取消加载。注意：不会删除已经下载的文件。
  @param url 视频文件地址 。为nil或者空，则取消全部。
 */
- (void)cancel:(NSString *)vid index:(int)index;

/**
 @brief 暂停加载。
  @param url 视频文件地址。 为nil或者空，则暂停全部。
 */
- (void)pause:(NSString *)vid index:(int)index;

/**
 @brief 恢复加载。
  @param url 视频文件地址。 为nil或者空，则恢复全部。
 */
- (void)resume:(NSString *)vid index:(int)index;

/**
 @brief 设置状态代理，参考AliMediaLoaderStatusDelegate
 @see AliMediaLoaderStatusDelegate
 */
- (void)setAliVodMediaLoaderStatusDelegate:(id<AliVodMediaLoaderStatusDelegate>)delegate;
@end
