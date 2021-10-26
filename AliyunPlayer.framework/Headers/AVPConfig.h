//
//  AVPConfig.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVPConfig_h
#define AVPConfig_h

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface AVPConfig : NSObject

/**
 @brief 直播最大延迟 默认5000毫秒，单位毫秒
 */
/****
 @brief The maximum broadcasting delay. Default: 5000 milliseconds, Unit: millisecond.
 */
@property (nonatomic, assign) int maxDelayTime;

/**
 @brief 卡顿后缓存数据的高水位，当播放器缓存数据大于此值时开始播放，单位毫秒
 */
/****
 @brief The size of data to be cached before the player can be resumed from playback lag. When the size of the data cached by the player reaches this value, the playback is resumed, Unit: millisecond.
 */
@property (nonatomic, assign) int highBufferDuration;

/**
 @brief 开始起播缓存区数据长度，默认500ms，单位毫秒
 */
/****
 @brief The size of the cache data required for starting playback. Default: 500 milliseconds, Unit: millisecond.
 */
@property (nonatomic, assign) int startBufferDuration;

/**
 @brief 播放器最大的缓存数据长度，默认50秒，单位毫秒
 */
/****
 @brief The maximum size of cache data. Default: 50 seconds, Unit: millisecond.
 */
@property (nonatomic, assign) int maxBufferDuration;

/**
 @brief 网络超时时间，默认15秒，单位毫秒
 */
/****
 @brief Network connection timeout time. Default: 15 seconds, Unit: millisecond.
 */
@property (nonatomic, assign) int networkTimeout;

/**
 @brief 网络重试次数，每次间隔networkTimeout，networkRetryCount=0则表示不重试，重试策略app决定，默认值为2
 */
/****
 @brief The maximum network reconnection attempts. Default: 2. networkTimeout specifies the reconnection interval. networkRetryCount=0 indicates that automatic network reconnection is disabled. The reconnection policy varies depending on the app.
 */
@property (nonatomic, assign) int networkRetryCount;

/**
 @brief probe数据大小，默认-1,表示不设置
 */
/****
 @brief The size of the probe data. Default: -1. Value -1 indicates that the probe data size is not specified. */
@property (nonatomic, assign) int maxProbeSize;

/**
 @brief 请求referer
 */
/****
 @brief Request Referer.
 */
@property (nonatomic, copy) NSString *referer;

/**
 @brief user Agent
 */
/****
 @brief UserAgent.
 */
@property (nonatomic, copy) NSString *userAgent;

/**
 @brief httpProxy代理
 */
/****
 @brief HTTP proxy.
 */
@property (nonatomic, copy) NSString *httpProxy;

/**
 @brief 调用stop停止后是否显示最后一帧图像，YES代表清除显示，黑屏，默认为NO
 */
/****
 @brief Whether to clear the last frame when the player is stopped. Set to YES to clear the last frame and a black view is displayed. Default: NO.
 */
@property (nonatomic, assign) BOOL clearShowWhenStop;

/**
 @brief 添加自定义header
 */
/****
 @brief Add a custom header.
 */
@property (nonatomic, copy) NSMutableArray *httpHeaders;

/**
 @brief 是否启用SEI
 */
/****
 @brief Enable or disable SEI.
 */
@property (nonatomic, assign) BOOL enableSEI;

/* set the video format for renderFrame callback
 * vtb decoder only, equal to OSType, not be supported by other decoder
  * support 420v 420f y420 BGRA
* */
@property (nonatomic, assign) int pixelBufferOutputFormat;

@property(nonatomic, assign) int liveStartIndex;
/**
 @brief 禁用Audio.
 */
/****
 @brief Disable audio track.
 */
@property (nonatomic, assign) BOOL disableAudio;

/**
 @brief 禁用Video
 */
/****
 @brief Disable video track.
 */
@property (nonatomic, assign) BOOL disableVideo;

/**
@brief  进度跟新的频率。包括当前位置和缓冲位置。
 */
/****
@brief Set the frequencies of Progress. Includes the current position and the buffer position.
 */
@property(nonatomic, assign) int positionTimerIntervalMs;

/**
 @brief 设置播放器后向buffer的最大值.
 */
/****
 @brief set the maximum backward buffer duration of the player.
 */
@property(nonatomic, assign) uint64_t mMAXBackwardDuration;

@end

#endif /* AVPConfig_h */
