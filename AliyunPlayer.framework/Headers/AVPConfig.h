//
//  AVPConfig.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVPConfig_h
#define AVPConfig_h

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface AVPConfig : NSObject

/**
 @brief 直播最大延迟 默认5000毫秒
 */
@property (nonatomic, assign) int maxDelayTime;

/**
 @brief 卡顿后缓存数据的高水位，当播放器缓存数据大于此值时开始播放
 */
@property (nonatomic, assign) int highBufferDuration;

/**
 @brief 开始起播缓存区数据长度，默认500ms
 */
@property (nonatomic, assign) int startBufferDuration;

/**
 @brief 播放器最大的缓存数据长度，默认50秒
 */
@property (nonatomic, assign) int maxBufferDuration;

/**
 @brief 网络超时时间，默认15秒
 */
@property (nonatomic, assign) int networkTimeout;

/**
 @brief 网络重试次数，每次间隔networkTimeout，networkRetryCount=0则表示不重试，重试策略app决定，默认值为2
 */
@property (nonatomic, assign) int networkRetryCount;

/**
 @brief probe数据大小，默认-1,表示不设置
 */
@property (nonatomic, assign) int maxProbeSize;

/**
 @brief 请求referer
 */
@property (nonatomic, copy) NSString *referer;

/**
 @brief user Agent
 */
@property (nonatomic, copy) NSString *userAgent;

/**
 @brief httpProxy代理
 */
@property (nonatomic, copy) NSString *httpProxy;

/**
 @brief 调用stop停止后是否显示最后一帧图像，YES代表清除显示，黑屏，默认为NO
 */
@property (nonatomic, assign) BOOL clearShowWhenStop;

/**
 @brief 添加自定义header
 */
@property (nonatomic, copy) NSMutableArray *httpHeaders;

@end

#endif /* AVPConfig_h */
