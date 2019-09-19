//
//  AVPLiveTimeShift.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliPlayer.h"

OBJC_EXPORT
@interface AVPLiveTimeShift : AliPlayer

/**
 @brief 直播时移，打开直播时移播放地址
 @param liveTimeUrl 直播时移播放地址
 */
/****
 @brief Send a request to the broadcasting timeshift URL.
 @param liveTimeUrl Broadcasting timeshift URL.
 */
- (void)prepareWithLiveTimeUrl:(NSString*)liveTimeUrl;

/**
 @brief 直播时移，设置直播时移地址
 @param liveTimeShiftUrl 直播时移请求地址
 */
/****
 @brief Set a broadcasting timeshift URL.
 @param liveTimeShiftUrl Broadcasting timeshift URL.
 */
- (void)setLiveTimeShiftUrl:(NSString*)liveTimeShiftUrl;

/**
 @brief 直播时移，跳转到指定时移位置
 @param startTime 跳转到直播startTime位置
 */
/****
 @brief Seek to a specified position.
 @param startTime Seek to the position specified by startTime in broadcasting.
 */
- (void)seekToLiveTime:(NSTimeInterval)startTime;

/**
 @brief 直播时移，获取直播时间
 */
/****
 @brief Query the broadcasting time.
 */
@property (nonatomic, assign) NSTimeInterval liveTime;

/**
 @brief 直播时移，获取当前播放时间
 */
/****
 @brief Query the current playback time.
 */
@property (nonatomic, assign) NSTimeInterval currentPlayTime;

/**
 @brief 直播时移，每60秒更新用户时移时间，参考AliyunPlayerVideoTimeShiftModel
 */
/****
 @brief Update the user timeshifting time at an interval of 60 seconds. See AliyunPlayerVideoTimeShiftModel.
 */
@property (nonatomic, strong) AVPTimeShiftModel *timeShiftModel;


/**
 @brief 停止播放
 */
/****
 @brief Stop the player.
 */
-(void)stop;


/**
 @brief 开始播放
 */
/****
 @brief Start the player.
 */
-(void)start;

@end
