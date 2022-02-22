
#import <AliyunPlayer/AVPDef.h>
#import <Foundation/Foundation.h>


@protocol AliMediaLoaderStatusDelegate <NSObject>
@optional

/**
 @brief 错误回调
 @param url 加载url
 @param code 错误码
 @param msg 错误描述
 */
/****
 @brief Error callback
 @param url  the load URL
 @param code Error code
 @param msg Error description
*/
- (void)onError:(NSString *)url code:(int64_t)code msg:(NSString *)msg;

/**
 @brief 完成回调
 @param url 加载url
 */
/****
 @brief Completed callback
 @param URL the load URL
*/
- (void)onCompleted:(NSString *)url;

/**
 @brief 取消回调
 @param url 加载url
 */
/****
 @brief  the Canceled  callback
 @param URL the load URL
*/
- (void)onCanceled:(NSString *)url;

@end


OBJC_EXPORT
@interface AliMediaLoader : NSObject

+ (instancetype)shareInstance;

/**
 @brief  开始加载文件。异步加载。可以同时加载多个。
 @param url  视频文件地址
 @param duration 加载的时长大小.单位：毫秒
 */
/****
 @brief Start load. Asynchronous loading. You can load more than one at a time.
 @param url Video file url
 @param duration Load duration. Unit: millisecond
*/
- (void)load:(NSString *)url duration:(int64_t)duration;

/**
  @brief 取消加载。注意：不会删除已经下载的文件。
  @param url 视频文件地址 。为nil或者空，则取消全部。
 */
/****
 @brief Cancel load. Note: Downloaded files will not be deleted.
 @param url Video file url. Nil or null, cancel all.
*/
- (void)cancel:(NSString *)url;

/**
 @brief 暂停加载。
  @param url 视频文件地址。 为nil或者空，则暂停全部。
 */
/****
 @brief pause load.
 @param url Video file url. Nil or null, pause all.
*/
- (void)pause:(NSString *)url;

/**
 @brief 恢复加载。
 @param url 视频文件地址。 为nil或者空，则恢复全部。
 */
/****
 @brief Resume load.
 @param url Video file url. Nil or null, resume all.
*/
- (void)resume:(NSString *)url;

/**
 @brief 设置状态代理，参考AliMediaLoaderStatusDelegate
 @see AliMediaLoaderStatusDelegate
 */
/****
 @brief, set the status Delegate
 @see AliMediaLoaderStatusDelegate
*/
- (void)setAliMediaLoaderStatusDelegate:(id<AliMediaLoaderStatusDelegate>)delegate;
@end
