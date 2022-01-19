//
//  AliPlayer.h
//  AliPlayer
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVPDelegate.h"
#import "AVPSource.h"
#import "AVPDef.h"
#import "AVPMediaInfo.h"
#import "AVPConfig.h"
#import "AVPCacheConfig.h"
@protocol CicadaAudioSessionDelegate;
@protocol CicadaRenderDelegate;
@protocol CicadaRenderingDelegate;

OBJC_EXPORT
@interface AliPlayer : NSObject

/**
 @brief 初始化播放器
 */
/****
 @brief Initialize the player.
 */
- (instancetype)init;

/**
 @brief 初始化播放器
 @param traceID 便于跟踪日志，设为"DisableAnalytics"可关闭日志分析系统（不推荐）。
 */
/****
 @brief Initialize the player.
 @param traceID A trace ID for debugging. Set as "DisableAnalytics" to disable report analytics data to server(not recommended).
 */
- (instancetype)init:(NSString*)traceID;

/**
 @brief 使用url方式来播放视频
 @param source AVPUrlSource的输入类型
 @see AVPUrlSource
 */
/****
 @brief Play by URL.
 @param source AVPUrlSource type.
 @see AVPUrlSource
 */
- (void)setUrlSource:(AVPUrlSource*)source;

/**
 @brief 使用bitstream方式来播放视频
 @param source AVPBitStreamSource的输入类型
 @see AVPBitStreamSource
 */
/****
 @brief Play by bit stream.
 @param source AVPBitStreamSource type.
 @see AVPBitStreamSource
 */
- (void)setBitStreamSource:(AVPBitStreamSource *)source;

/**
 @brief 用vid和sts来播放视频，sts可参考：https://help.aliyun.com/document_detail/28756.html?spm=a2c4g.11186623.4.4.6f554c07q7B7aS
 @param source AVPVidStsSource的输入类型
 @see AVPVidStsSource
 */
/****
 @brief Play by VID and STS. For STS, see https://help.aliyun.com/document_detail/28756.html?spm=a2c4g.11186623.4.4.6f554c07q7B7aS
 @param source AVPVidStsSource type.
 @see AVPVidStsSource
 */
- (void)setStsSource:(AVPVidStsSource*)source;

/**
 @brief 用vid和MPS信息来播放视频。可参考：https://help.aliyun.com/document_detail/53522.html?spm=5176.doc53534.2.5.mhSfOh
 @param source AVPVidMpsSource的输入类型
 @see AVPVidMpsSource
 */
/****
 @brief Play by VID and MPS. See https://help.aliyun.com/document_detail/53522.html?spm=5176.doc53534.2.5.mhSfOh
 @param source AVPVidMpsSource type.
 @see AVPVidMpsSource
 */
- (void)setMpsSource:(AVPVidMpsSource*)source;

/**
 @brief 使用vid+playauth方式播放。可参考：https://help.aliyun.com/document_detail/57294.html
 @param source AVPVidAuthSource的输入类型
 @see AVPVidAuthSource
 */
/****
 @brief Play by VID and playauth. See https://help.aliyun.com/document_detail/57294.html
 @param source AVPVidAuthSource type.
 @see AVPVidAuthSource
 */
- (void)setAuthSource:(AVPVidAuthSource*)source;

- (void)setLiveStsSource:(AVPLiveStsSource*)source;

- (void)updateLiveStsInfo:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;

/**
 @brief 播放准备，异步
 */
/****
 @brief Prepare for playback. Asynchronous callback.
 */
-(void)prepare;

/**
 @brief 开始播放
 */
/****
 @brief Start playing.
 */
-(void)start;

/**
 @brief 暂停播放
 */
/****
 @brief Pause.
 */
-(void)pause;

/**
 @brief 刷新view，例如view size变化时。
 */
/****
 @brief Refresh the view in certain situations, for example, when the size of the view changes.
 */
- (void)redraw DEPRECATED_MSG_ATTRIBUTE("will not take effect");

/**
 @brief 清空画面。
 */
/****
 @brief Clear screen.
 */
- (void)clearScreen;

/**
 @brief 重置播放
 */
/****
 @brief Reset.
 */
-(void)reset;

/**
 @brief 停止播放
 */
/****
 @brief Stop.
 */
-(void)stop;

/**
 @brief 销毁播放器
 */
/****
 @brief Delete the player.
 */
-(void)destroy;

/**
 @brief 跳转到指定的播放位置
 @param time 新的播放位置，单位毫秒
 @param seekMode seek模式
 @see AVPSeekMode
 */
/****
 @brief Seek to a specified position.
 @param time The specified position that the player will seek to, Unit: millisecond.
 @param seekMode Seek mode.
 @see AVPSeekMode
 */
-(void)seekToTime:(int64_t)time seekMode:(AVPSeekMode)seekMode;

/**
 * 设置精准seek的最大间隔。
 * @param delta 间隔时间，单位毫秒
 */
/****
* set the maximum interval of precision seek.
* @param delta interval in milliseconds
*/
-(void)setMaxAccurateSeekDelta:(int)delta;

/**
 @brief 截图 AVPImage: mac平台返回NSImage，iOS平台返回UIImage
 */
/****
 @brief Snapshot. AVPImage: For a Mac platform, NSImage is returned. For an iOS platform, UIImage is returned.
 */
-(void) snapShot;

/**
 @brief 根据trackIndex，切换清晰度
 @param trackIndex 选择清晰度的index，SELECT_AVPTRACK_TYPE_VIDEO_AUTO代表自适应码率
 */
/****
 @brief Switch definition according to the specified track index.
 @param trackIndex Specify a definition index. SELECT_AVPTRACK_TYPE_VIDEO_AUTO: auto bitrate adjustment.
 */
-(void)selectTrack:(int)trackIndex;

/**
 @brief 根据trackIndex，切换清晰度
 @param trackIndex 选择清晰度的index，SELECT_AVPTRACK_TYPE_VIDEO_AUTO代表自适应码率
 @param accurate 是否精准跳转。
 */
/****
 @brief Switch definition according to the specified track index.
 @param trackIndex Specify a definition index. SELECT_AVPTRACK_TYPE_VIDEO_AUTO: auto bitrate adjustment.
 @param accurate Use accurate seeking to select track。
 */
-(void)selectTrack:(int)trackIndex accurate:(BOOL)accurate;

/**
 @brief 获取媒体信息，包括track信息
 */
/****
 @brief Query media information, including track information.
 */
-(AVPMediaInfo*) getMediaInfo;

/**
 @brief 获取当前播放track
 @param type track类型
 @see AVPTrackType
 */
/****
 @brief Query the track that is being played.
 @param type Track type.
 @see AVPTrackType
 */
-(AVPTrackInfo*) getCurrentTrack:(AVPTrackType)type;

/**
 @brief 设置缩略图URL
 @param URL 缩略图URL
 */
/****
 @brief Specify a thumbnail image URL.
 @param URL The specified thumbnail image URL.
 */
-(void) setThumbnailUrl:(NSString *)URL;

/**
 @brief 获取指定位置的缩略图
 @param positionMs 代表在哪个指定位置的缩略图
 */
/****
 @brief Retrieve the thumbnail image at the specified position.
 @param positionMs The specified position.
 */
-(void)getThumbnail:(int64_t)positionMs;

/**
 @brief 用于跟踪debug信息
 @param traceID 指定和其他客户端连接可跟踪的id
 */
/****
 @brief Set a trace ID for debugging.
 @param traceID The specified client connection trace ID.
 */
- (void) setTraceID:(NSString*)traceID;


/**
 @brief 设置转换播放的url的回调函数，一般用于p2p中的url地址转换
 @param callback 回调函数指针
 */
/****
 @brief Set a URL conversion callback. URL conversion is typically used in P2P broadcasting.
 @param callback The function pointer of the callback.
 */
- (void) setPlayUrlConvertCallback:(PlayURLConverCallback)callback;
/**
 @brief 播放器设置
 @param config AVPConfig类型
 @see AVPConfig
 */
/****
 @brief Modify player configuration.
 @param config AVPConfig type.
 @see AVPConfig
 */
-(void) setConfig:(AVPConfig*)config;

/**
 @brief 获取播放器设置
 @see AVPConfig
 */
/****
 @brief Query player configuration.
 @see AVPConfig
 */
-(AVPConfig*) getConfig;

/**
 @brief 设置缓存配置
 @param AVPCacheConfig 缓存配置。{@link AVPCacheConfig}。
 @return 设置成功返回YES
 */
/****
 @brief Modify cache configuration.
 @param AVPCacheConfig Cache configuration. {@link AVPCacheConfig}.
 @return If the cache configuration is modified, YES is returned.
 */
-(BOOL) setCacheConfig:(AVPCacheConfig *)cacheConfig;

/**
 @brief 根据url获取缓存的文件名。如果有自定义的规则，请实现delegate {@link onGetCacheNameByURL}。
 @brief 如果没有实现delegate，将会采用默认逻辑生成文件名。
 @param URL URL
 * @return 最终缓存的文件名（不包括后缀。缓存文件的后缀名统一为.alv）。
 */
/****
 @brief Query the name of the cached file with the specified URL. If a custom rule is set, delegate {@link onGetCacheNameByURL}.
 @brief If the delegation failed, the default logic is used to generate the file name.
 @param URL The URL of the cached file.
 * @return The name of the cached file. The file extension is not included. All files use the .alv extension.
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
/****
 @brief Query the name of the cached file with the specified URL. If a custom rule is set, delegate {@link onCacheNameByVidCallback}.
 @brief If the delegation failed, the default logic is used to generate the file name.
 @param vid        The VID of the video.
 @param format     The format of the video.
 @param definition The definition of the video.
 @return The name of the cached file. The file extension is not included. All files use the .alv extension.
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
/****
 @brief Query the name of the cached file with the specified URL. If a custom rule is set, delegate {@link onCacheNameByVidCallback}.
 @brief If the delegation failed, the default logic is used to generate the file name.
 @param vid        The VID of the video.
 @param format     The format of the video.
 @param definition The definition of the video.
 @param previewTime The preview duration of the video.
 @return The name of the cached file. The file extension is not included. All files use the .alv extension.
 */
-(NSString *) getCacheFilePath:(NSString *)vid format:(NSString *)format definition:(NSString *)definition previewTime:(int)previewTime;

/**
 @brief 添加外挂字幕。
 @param URL 字幕地址
 */
/****
 @brief Add external subtitles
 @param URL subtitle address
 */
-(void) addExtSubtitle:(NSString *)URL;

/**
 @brief 选择外挂字幕
 @param trackIndex 字幕索引
 @param enable true：选择，false：关闭
 */
/****
 @brief Select external subtitles
 @param trackIndex caption index
 @param enable true: select, false: close
 */
-(void) selectExtSubtitle:(int)trackIndex enable:(BOOL)enable;

/**
 * 设置某路流相对于主时钟的延时时间，默认是0, 目前只支持外挂字幕
 * @param index 流的索引
 * @param time  延时，单位毫秒
 */
/****
 * set the delay time of the stream
 * @param index steam index
 * @param time  ms
 */

- (void)setStreamDelayTime:(int)index time:(int)time;


/**
 @brief 重新加载。比如网络超时时，可以重新加载。
 */
/****
 @brief Reload resources. You can reload resources when the network connection times out.
 */
-(void) reload;

/**
 @brief 根据key获取相应的信息。
 @param key 关键字枚举值
 * @return 相应信息（找不到相应信息返回空字符串）。
 */
/****
 @brief Get information by key.
 @param key The enum of key
 * @return corresponding information, return "" if doesn't exist.
 */
-(NSString *) getPropertyString:(AVPPropertyKey)key;

/**
 @brief 设置多码率时默认播放的码率。将会选择与之最接近的一路流播放。
 @param bandWidth 播放的码率。
 */
/****
 @brief Set the default playback bitrate for multi-bit rate. The nearest stream will be selected.
 @param bandWidth bit rate .
 */
-(void) setDefaultBandWidth:(int)bandWidth;

#if TARGET_OS_IPHONE
/**
 @brief 设置视频的背景色
 @param color  the color
 */
/****
 @brief Set video background color
 @param color  the color
 */
-(void) setVideoBackgroundColor:(UIColor *)color;

/**
 @brief 设置视频快速启动
 @param enable  true：开启，false：关闭
 */
/****
 @brief Set video fast start
 @param enable  true：enable，false: disable
 */
-(void) setFastStart:(BOOL)enable;

/**
 @brief 设置ip解析类型
 @param type  ip解析类型
 */
/****
 @brief Set ip resolve type
 @param type ip resolve type
 */
-(void) setIPResolveType:(AVPIpResolveType)type;
#endif

/**
 @brief 设置代理 参考AVPEventReportParamsDelegate
 @see AVPEventReportParamsDelegate
 */
/****
 @brief Set a proxy.  See AVPEventReportParamsDelegate.
 @see AVPEventReportParamsDelegate
*/
-(void) setEventReportParamsDelegate:(id<AVPEventReportParamsDelegate>)delegate;

/**
 * @brief 获取播放器的参数
 *
 * @param key 参数值
 * @return 相关信息
 */
/****
 * @brief Get player information
 *
 * @param key The key
 * @return The information
 */
-(NSString *) getOption:(AVPOption)key;


/**
 @brief 向播放器的组件发送命令。
 @param content 命令内容。
 @return 命令执行结果， < 0 失败。
 */
/****
 @brief Send command to component
 @param content command content
 @return < 0 on Error
 */

- (int)invokeComponent:(NSString *)content;
/**
 @brief 获取SDK版本号信息
 */
/****
 @brief Query the SDK version.
 */
+ (NSString*) getSDKVersion;

/**
 @brief 获取设备UUID
 */
/****
 @brief Query device UUID.
 */
+ (NSString *)getDeviceUUID;

/**
 @brief 初始化播放器组件。这些组件是可裁剪的。App可删除相应动态库，去掉初始化组件代码，实现裁剪。
 */
/****
 @brief Initialize player components. These components are optional. You can remove these components by deleting the dynamic libraries and code of the components on your app.
 */
+ (void) initPlayerComponent:(NSString *)functionName function:(void*)function;

/**
 @brief 设置是否静音，支持KVO
 */
/****
 @brief Mute or unmute the player. KVO is supported.
 */
@property(nonatomic, getter=isMuted) BOOL muted;

/**
 @brief 播放速率，0.5-2.0之间，1为正常播放，支持KVO
 */
/****
 @brief Set the playback speed. Valid values: 0.5 to 2.0. Value 1 indicates normal speed. KVO is supported.
 */
@property(nonatomic) float rate;

/**
 @brief 是否开启硬件解码，支持KVO
 */
/****
 @brief Enable or disable hardware decoding. KVO is supported.
 */
@property(nonatomic) BOOL enableHardwareDecoder;

/**
 @brief 设置是否循环播放，支持KVO
 */
/****
 @brief Enable or disable loop playback. KVO is supported.
 */
@property(nonatomic, getter=isLoop) BOOL loop;

/**
 @brief 设置是否自动播放，支持KVO
 */
/****
 @brief Enable or disable autoplay. KVO is supported.
 */
@property(nonatomic, getter=isAutoPlay) BOOL autoPlay;

/**
 @brief 渲染镜像模式，支持KVO
 @see AVPMirrorMode
 */
/****
 @brief Set a mirroring mode. KVO is supported.
 @see AVPMirrorMode
 */
@property(nonatomic) AVPMirrorMode mirrorMode;

/**
 @brief 渲染旋转模式，支持KVO
 @see AVPRotateMode
 */
/****
 @brief Set a rotate mode. KVO is supported.
 @see AVPRotateMode
 */
@property(nonatomic) AVPRotateMode rotateMode;

/**
 @brief 渲染填充模式，支持KVO
 @see AVPScalingMode
 */
/****
 @brief Set a zoom mode. KVO is supported.
 @see AVPScalingMode
 */
@property(nonatomic) AVPScalingMode scalingMode;


/**
 @brief 设置播放器的视图playerView
 * AVPView: mac下为NSOpenGLView，iOS下为UIView
 */
/****
 @brief Set a player view (playerView).
 * AVPView: Mac platform: NSOpenGLView. iOS platform: UIView.
 */
@property(nonatomic, strong) AVPView* playerView;

/**
 @brief 获取视频的宽度，支持KVO
 */
/****
 @brief Query the width of the video. KVO is supported.
 */
@property (nonatomic, readonly) int width;

/**
 @brief 获取视频的高度，支持KVO
 */
/****
 @brief Query the height of the video. KVO is supported.
 */
@property (nonatomic, readonly) int height;

/**
 @brief 获取视频的旋转角度，从metadata中获取出来，支持KVO
 */
/****
 @brief Query the rotate angle of the video, which is retrieved from the video metadata. KVO is supported.
 */
@property (nonatomic, readonly) int rotation;

/**
 @brief 获取/设置播放器的音量（非系统音量），支持KVO，范围0.0~2.0，当音量大于1.0时，可能出现噪音，不推荐使用。
 */
/****
 @brief Query or set the volume of the player(Not system volume). KVO is supported. The range is 0.0~2.0，it maybe lead to noise if set volume more then 1.0, not recommended.
 */
@property (nonatomic, assign) float volume;

/**
 @brief 获取视频的长度，支持KVO
 */
/****
 @brief Query the length of the video. KVO is supported.
 */
@property (nonatomic, readonly) int64_t duration;

/**
 @brief 获取当前播放位置，支持KVO
 */
/****
 @brief Query the current playback position. KVO is supported.
 */
@property (nonatomic, readonly) int64_t currentPosition;

/**
@brief 获取当前播放位置的utc时间，支持KVO
*/
/****
@brief Query the current playback utc time. KVO is supported.
*/
@property(nonatomic, readonly) int64_t currentUtcTime;


/**
 @brief 获取当前下载速度，支持KVO
 */
/****
 @brief Query the current download speed. KVO is supported.
 */
@property(nonatomic, readonly) int64_t currentDownloadSpeed;

/**
 @brief 获取已经缓存的位置，支持KVO
 */
/****
 @brief Query the buffered position. KVO is supported.
 */
@property (nonatomic, readonly) int64_t bufferedPosition;

/**
 @brief 设置代理，参考AVPDelegate
 @see AVPDelegate
 */
/****
 @brief Set a proxy. See AVPDelegate.
 @see AVPDelegate
 */
@property (nonatomic, weak) id<AVPDelegate> delegate;

/**
 * 设置渲染回调。
 */
@property(nonatomic, weak) id<CicadaRenderDelegate> renderDelegate __deprecated;

@property(nonatomic, weak) id<CicadaRenderingDelegate> renderingDelegate;

@property (nonatomic, weak) id <AVPEventReportParamsDelegate> eventReportParamsDelegate;


/**
 @brief 设置AudioSession的Delegate
 @param delegate Delegate对象
 */
/****
 @brief 设置AudioSession的Delegate
 @param delegate Delegate对象
 */
+ (void)setAudioSessionDelegate:(id<CicadaAudioSessionDelegate>)delegate;

/**
 @brief 是否打开log输出
 @param enableLog true表示输出log
 @see 使用setLogCallbackInfo
 */
/****
 @brief Enable or disable logging.
 @param enableLog set as true to output log
 @see Use setLogCallbackInfo.
 */
+(void)setEnableLog:(BOOL)enableLog;

/**
 @brief 设置日志打印回调block，异步
 @param logLevel log输出级别
 @param callbackBlock log回调block，可以为nil
 */
/****
 @brief Set a log output callback block. Asynchronous.
 @param logLevel The level of the log.
 @param callbackBlock Log output callback block, which can be nil.
 */
+(void) setLogCallbackInfo:(AVPLogLevel)logLevel callbackBlock:(void (^)(AVPLogLevel logLevel,NSString* strLog))block;

-(void) setVerifyStsCallback:(AVPStsStatus (^)(AVPStsInfo info)) callback;
/**
 @brief 设置期望使用的播放器名字。
 @param name 期望使用的播放器名字
 */
/****
 @brief Set preper player name.
 @param name preper player name.
 */
- (void)setPreferPlayerName:(NSString *)name;
/**
 @brief 获取播放时使用的播放器名字
 */
/****
 @brief Get used player name
 */
- (NSString *)getPlayerName;

/**
 @brief 设置视频标签。值范围[0,99]。
 */
/****
 @brief Set the video tags. Values range from [0,99].
 */
- (void)setVideoTag:(int *)tags size:(int)size;

/**
 @brief 发送用户自定义事件，将通过AVPEventReportParamsDelegate回调。事件 e = 5001。
 */
/****
 @brief Send custom event, will callback through AVPEventReportParamsDelegate. Event id e = 5001.
 */
- (void)sendCustomEvent:(NSString *)args;


/**
 @brief 重连所有网络连接，网络路由发生变化后，调用此接口，可以让播放器所有的连接切换到新的路由上去。
 */
/****
 @brief reconnect all connections, call this when netWork router changed, and the player will use new router.
 */

+ (void)netWorkReConnect;

@end
