//
//  AliListPlayer.h
//  AliListPlayer
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliPlayer.h"
OBJC_EXPORT
@interface AliListPlayer : AliPlayer

/**
 @brief 初始化播放列表
 */
/****
 @brief Initialize the playlist.
 */
- (instancetype)init;

/**
 @brief 初始化播放器
 @param traceID 用于跟踪debug信息
 */
/****
 @brief Initialize the player.
 @param traceID The trace ID for debugging.
 */
- (instancetype)init:(NSString*)traceID;

- (void)stop;

- (void)destroy;
/**
 @brief 添加资源到播放列表中
 @param vid vid的播放方式
 @param uid 该资源的uid，代表在列表中的唯一标识
 */
/****
 @brief Add a resource to the playlist.
 @param vid Specify a resource by VID.
 @param uid The UID of the resource, which uniquely identifies a resource.
 */
- (void) addVidSource:(NSString*)vid uid:(NSString*)uid;

/**
 @brief 添加资源到播放列表中
 @param url url的播放方式
 @param uid 该资源的uid，代表在列表中的唯一标识
 */
/****
 @brief Add a resource to the playlist.
 @param url Specify a resource by URL.
 @param uid The UID of the resource, which uniquely identifies a resource.
 */
- (void) addUrlSource:(NSString*)url uid:(NSString*)uid;

/**
 @brief 从播放列表中删除指定资源
 @param uid 该资源的uid，代表在列表中的唯一标识
 */
/****
 @brief Remove a resource from the playlist.
 @param uid The UID of the resource, which uniquely identifies a resource.
 */
- (void) removeSource:(NSString*)uid;

/**
 @brief 清除播放列表
 */
/****
 @brief Clear the playlist.
 */
- (void) clear;

/**
 @brief 获取当前播放资源的uid
 */
/****
 @brief Query the UID of the resource that is being played.
 */
- (NSString*) currentUid;

/**
 @brief 当前位置移动到下一个进行准备播放,url播放方式
 */
/****
 @brief Seek to the next resource and prepare for playback. Only playback by URL is supported.
 */
- (BOOL) moveToNext;

/**
 @brief 当前位置移动到上一个进行准备播放,url播放方式
 */
/****
 @brief Seek to the previous resource and prepare for playback. Only playback by URL is supported.
 */
- (BOOL) moveToPre;

/**
 @brief 移动到指定位置开始准备播放,url播放方式
 @param uid 指定资源的uid，代表在列表中的唯一标识
 */
/****
 @brief Seek to the specified position and prepare for playback. Only playback by URL is supported.
 @param uid The UID of the specified resource, which uniquely identifies a resource.
 */
- (BOOL) moveTo:(NSString*)uid;

/**
 @brief 当前位置移动到下一个进行准备播放，sts播放方式，需要更新sts信息
 @param accId vid sts播放方式的accessKeyID
 @param accKey vid sts播放方式的accessKeySecret
 @param token vid sts播放方式的securtiToken
 @param region vid sts播放方式的region 默认cn-shanghai
 */
/****
 @brief Seek to the next resource and prepare for playback. Only playback by STS is supported. You must update the STS information.
 @param accId vid The AccessKey ID.
 @param accKey vid The AccessKey Secret.
 @param token vid The STS token.
 @param region vid The specified region. Default: cn-shanghai.
 */
- (BOOL) moveToNext:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;

/**
 @brief 当前位置移动到上一个进行准备播放，sts播放方式，需要更新sts信息
 @param accId vid sts播放方式的accessKeyID
 @param accKey vid sts播放方式的accessKeySecret
 @param token vid sts播放方式的securtiToken
 @param region vid sts播放方式的region 默认cn-shanghai
 */
/****
 @brief Seek to the previous resource and prepare for playback. Only playback by STS is supported. You must update the STS information.
 @param accId vid The AccessKey ID.
 @param accKey vid The AccessKey Secret.
 @param token vid The STS token.
 @param region vid The specified region. Default: cn-shanghai.
 */
- (BOOL) moveToPre:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;

/**
 @brief 移动到指定位置开始准备播放，sts播放方式，需要更新sts信息
 @param uid 指定资源的uid，代表在列表中的唯一标识
 @param accId vid sts播放方式的accessKeyID
 @param accKey vid sts播放方式的accessKeySecret
 @param token vid sts播放方式的securtiToken
 @param region vid sts播放方式的region 默认cn-shanghai
 */
/****
 @brief Seek to the specified resource and prepare for playback. Only playback by STS is supported. You must update the STS information.
 @param uid The UID of the specified resource, which uniquely identifies a resource.
 @param accId vid The AccessKey ID.
 @param accKey vid The AccessKey Secret.
 @param token vid The STS token.
 @param region vid The specified region. Default: cn-shanghai.
 */
- (BOOL) moveTo:(NSString*)uid accId:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;


/**
 @brief 设置最大的预缓存的内存大小，默认100M，最小20M
 */
/****
 @brief Set the maximum preloading cache size. Default: 100 MB. Minimum: 20 MB.
 */
@property (nonatomic, assign) int maxPreloadMemorySizeMB;


/**
 @brief 获取/设置预加载的个数，当前位置的前preloadCount和后preloadCount，默认preloadCount = 2
 */
/****
 @brief Query or set the number of preloaded resources. The number of resources before preloading and the number of resources after preloading are returned. Default: 2.
 */
@property (nonatomic, assign) int preloadCount;

/**
 @brief 获取/设置列表播放的sts播放方式，指定默认的清晰度，如"LD、HD"等，moveTo之前调用，一旦预加载后不能更改
 */
/****
 @brief Query or set the definition for playback by STS, such as LD or HD. Call this method before moveTo. After the resources are preloaded, you cannot change the definition.
 */
@property (nonatomic, copy) NSString* stsPreloadDefinition;

@end

