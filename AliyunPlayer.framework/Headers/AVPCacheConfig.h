//
//  AVPCacheConfig.h
//  AliPlayerSDK
//
//  Created by huang_jiafa on 2019/05/31.
//  Copyright (c) 2019 Aliyun. All rights reserved.
//

#ifndef AVPCacheConfig_h
#define AVPCacheConfig_h

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface AVPCacheConfig : NSObject

/**
 @brief 缓存目录
 */
@property (nonatomic, copy) NSString *path;

/**
 @brief 单个视频缓存的最大时长，单位秒，即某个视频的时长超过maxDuration将不会被缓存
 */
@property (nonatomic, assign) long maxDuration;

/**
 @brief 所有缓存最大占用空间，单位：MB
 */
@property (nonatomic, assign) int maxSizeMB;

/**
 @brief 是否开启缓存。默认关闭。
 */
@property (nonatomic, assign) BOOL enable;

@end

#endif /* AVPCacheConfig_h */
