//
//  AVPLiveTimeShift.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliPlayer.h"

OBJC_EXPORT
@interface AVPLiveTimeShift : AliPlayer

/**
 @brief 直播时移，打开直播时移播放地址
 @param liveTimeUrl 直播时移播放地址
 */
- (void)prepareWithLiveTimeUrl:(NSString*)liveTimeUrl;

/**
 @brief 直播时移，设置直播时移地址
 @param liveTimeShiftUrl 直播时移请求地址
 */
- (void)setLiveTimeShiftUrl:(NSString*)liveTimeShiftUrl;

/**
 @brief 直播时移，跳转到指定时移位置
 @param startTime 跳转到直播startTime位置
 */
- (void)seekToLiveTime:(NSTimeInterval)startTime;

/**
 @brief 直播时移，获取直播时间
 */
@property (nonatomic, assign) NSTimeInterval liveTime;

/**
 @brief 直播时移，获取当前播放时间
 */
@property (nonatomic, assign) NSTimeInterval currentPlayTime;

/**
 @brief 直播时移，每60秒更新用户时移时间，参考AliyunPlayerVideoTimeShiftModel
 */
@property (nonatomic, strong) AVPTimeShiftModel *timeShiftModel;


/**
 @brief 停止播放
 */
-(void)stop;


/**
 @brief 开始播放
 */
-(void)start;

@end
