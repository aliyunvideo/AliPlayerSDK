//
//  AliPlayer.h
//  AliPlayer
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVPDelegate.h"
#import "AVPSource.h"
#import "AVPDef.h"
#import "AVPMediaInfo.h"
#import "AVPConfig.h"
#import "AVPCacheConfig.h"

OBJC_EXPORT
@interface AliPlayer : NSObject

/**
 @brief 初始化播放器
 */
- (instancetype)init;

/**
 @brief 初始化播放器
 @param traceID 用于跟踪debug信息
 */
- (instancetype)init:(NSString*)traceID;

/**
 @brief 使用url方式来播放视频
 @param source AVPUrlSource的输入类型
 @see AVPUrlSource
 */
- (void)setUrlSource:(AVPUrlSource*)source;

/**
 @brief 用vid和sts来播放视频，sts可参考：https://help.aliyun.com/document_detail/28756.html?spm=a2c4g.11186623.4.4.6f554c07q7B7aS
 @param source AVPVidStsSource的输入类型
 @see AVPVidStsSource
 */
- (void)setStsSource:(AVPVidStsSource*)source;

/**
 @brief 用vid和MPS信息来播放视频。可参考：https://help.aliyun.com/document_detail/53522.html?spm=5176.doc53534.2.5.mhSfOh
 @param source AVPVidMpsSource的输入类型
 @see AVPVidMpsSource
 */
- (void)setMpsSource:(AVPVidMpsSource*)source;

/**
 @brief 使用vid+playauth方式播放。可参考：https://help.aliyun.com/document_detail/57294.html
 @param source AVPVidAuthSource的输入类型
 @see AVPVidAuthSource
 */
- (void)setAuthSource:(AVPVidAuthSource*)source;

/**
 @brief 播放准备，异步
 */
-(void)prepare;

/**
 @brief 开始播放
 */
-(void)start;

/**
 @brief 暂停播放
 */
-(void)pause;

/**
 @brief 刷新view，例如view size变化时。
 */
-(void)redraw;

/**
 @brief 重置播放
 */
-(void)reset;

/**
 @brief 停止播放
 */
-(void)stop;

/**
 @brief 销毁播放器
 */
-(void)destroy;

/**
 @brief 跳转到指定的播放位置
 @param time 新的播放位置
 @param seekMode seek模式
 @see AVPSeekMode
 */
-(void)seekToTime:(int64_t)time seekMode:(AVPSeekMode)seekMode;

/**
 @brief 截图 AVPImage: mac平台返回NSImage，iOS平台返回UIImage
 */
-(void) snapShot;

/**
 @brief 根据trackIndex，切换清晰度
 @param trackIndex 选择清晰度的index，SELECT_AVPTRACK_TYPE_VIDEO_AUTO代表自适应码率
 */
-(void)selectTrack:(int)trackIndex;

/**
 @brief 获取媒体信息，包括track信息
 */
-(AVPMediaInfo*) getMediaInfo;

/**
 @brief 获取当前播放track
 @param type track类型
 @see AVPTrackType
 */
-(AVPTrackInfo*) getCurrentTrack:(AVPTrackType)type;

/**
 @brief 获取指定位置的缩略图
 @param positionMs 代表在哪个指定位置的缩略图
 */
-(void)getThumbnail:(int64_t)positionMs;

/**
 @brief 用于跟踪debug信息
 @param traceID 指定和其他客户端连接可跟踪的id
 */
- (void) setTraceID:(NSString*)traceID;


/**
 @brief 设置转换播放的url的回调函数，一般用于p2p中的url地址转换
 @param callback 回调函数指针
 */
- (void) setPlayUrlConvertCallback:(PlayURLConverCallback)callback;

/**
 @brief 播放器设置
 @param config AVPConfig类型
 @see AVPConfig
 */
-(void) setConfig:(AVPConfig*)config;

/**
 @brief 获取播放器设置
 @see AVPConfig
 */
-(AVPConfig*) getConfig;

/**
 @brief 设置缓存配置
 @param AVPCacheConfig 缓存配置。{@link AVPCacheConfig}。
 @return 设置成功返回YES
 */
-(BOOL) setCacheConfig:(AVPCacheConfig *)cacheConfig;

/**
 @brief 根据url获取缓存的文件名。如果有自定义的规则，请实现delegate {@link onGetCacheNameByURL}。
 @brief 如果没有实现delegate，将会采用默认逻辑生成文件名。
 @param URL URL
 * @return 最终缓存的文件名（不包括后缀。缓存文件的后缀名统一为.alv）。
 */
-(NSString *) getCacheFilePath:(NSString *)URL;

/**
 @brief 根据url获取缓存的文件名。如果有自定义的规则，请实现delegate {@link onCacheNameByVidCallback}。
 @brief 如果没有实现delegate，将会采用默认逻辑生成文件名。
 @param vid        视频id
 @param format     视频格式
 @param definition 视频清晰度
 @return 最终缓存的文件名（不包括后缀。缓存文件的后缀名统一为.alv）。
 */
-(NSString *) getCacheFilePath:(NSString *)vid format:(NSString *)format definition:(NSString *)definition;

/**
 @brief 根据url获取缓存的文件名。如果有自定义的规则，请实现delegate {@link onCacheNameByVidCallback}。
 @brief 如果没有实现delegate，将会采用默认逻辑生成文件名。
 @param vid        视频id
 @param format     视频格式
 @param definition 视频清晰度
 @param previewTime 试看时长
 @return 最终缓存的文件名（不包括后缀。缓存文件的后缀名统一为.alv）。
 */
-(NSString *) getCacheFilePath:(NSString *)vid format:(NSString *)format definition:(NSString *)definition previewTime:(int)previewTime;

/**
 @brief 重新加载。比如网络超时时，可以重新加载。
 */
-(void) reload;

/**
 @brief 获取SDK版本号信息
 */
+ (NSString*) getSDKVersion;

/**
 @brief 初始化播放器组件。这些组件是可裁剪的。App可删除相应动态库，去掉初始化组件代码，实现裁剪。
 */
+ (void) initPlayerComponent:(NSString *)functionName function:(void*)function;

/**
 @brief 设置是否静音，支持KVO
 */
@property(nonatomic, getter=isMuted) BOOL muted;

/**
 @brief 播放速率，0.5-2.0之间，1为正常播放，支持KVO
 */
@property(nonatomic) float rate;

/**
 @brief 是否开启硬件解码，支持KVO
 */
@property(nonatomic) BOOL enableHardwareDecoder;

/**
 @brief 设置是否循环播放，支持KVO
 */
@property(nonatomic, getter=isLoop) BOOL loop;

/**
 @brief 设置是否自动播放，支持KVO
 */
@property(nonatomic, getter=isAutoPlay) BOOL autoPlay;

/**
 @brief 是否打开log输出
 @see 使用setLogCallbackInfo
 */
@property(nonatomic) BOOL enableLog;

/**
 @brief 渲染镜像模式，支持KVO
 @see AVPMirrorMode
 */
@property(nonatomic) AVPMirrorMode mirrorMode;

/**
 @brief 渲染旋转模式，支持KVO
 @see AVPRotateMode
 */
@property(nonatomic) AVPRotateMode rotateMode;

/**
 @brief 渲染填充模式，支持KVO
 @see AVPScalingMode
 */
@property(nonatomic) AVPScalingMode scalingMode;


/**
 @brief 设置播放器的视图playerView
 * AVPView: mac下为NSOpenGLView，iOS下为UIView
 */
@property(nonatomic, strong) AVPView* playerView;

/**
 @brief 获取视频的宽度，支持KVO
 */
@property (nonatomic, readonly) int width;

/**
 @brief 获取视频的高度，支持KVO
 */
@property (nonatomic, readonly) int height;

/**
 @brief 获取视频的旋转角度，从metadata中获取出来，支持KVO
 */
@property (nonatomic, readonly) int rotation;

/**
 @brief 获取/设置播放器的音量，支持KVO
 */
@property (nonatomic, assign) float volume;

/**
 @brief 获取视频的长度，支持KVO
 */
@property (nonatomic, readonly) int64_t duration;

/**
 @brief 获取当前播放位置，支持KVO
 */
@property (nonatomic, readonly) int64_t currentPosition;

/**
 @brief 获取已经缓存的位置，支持KVO
 */
@property (nonatomic, readonly) int64_t bufferedPosition;

/**
 @brief 设置代理，参考AVPDelegate
 @see AVPDelegate
 */
@property (nonatomic, weak) id<AVPDelegate> delegate;

/**
 @brief 设置日志打印回调block，异步
 @param logLevel log输出级别
 @param callbackBlock log回调block，可以为nil
 */
+(void) setLogCallbackInfo:(AVPLogLevel)logLevel callbackBlock:(void (^)(AVPLogLevel logLevel,NSString* strLog))block;

@end

