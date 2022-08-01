//
//  AliPlayerPictureInPictureDelegate.h
//  AliyunPlayer
//
//  Created by alibaba on 2022/7/4.
//  Copyright © 2022 com.alibaba.AliyunPlayer. All rights reserved.

#ifndef AliPlayerPictureInPictureDelegate_h
#define AliPlayerPictureInPictureDelegate_h

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#elif TARGET_OS_OSX
#import <AppKit/AppKit.h>
#endif

@protocol AliPlayerPictureInPictureDelegate <NSObject>

@optional

/**
 * 画中画准备启动
 */
- (void)pictureInPictureControllerWillStartPictureInPicture;

/**
 * 画中画已经启动
 */
- (void)pictureInPictureControllerDidStartPictureInPicture;

/**
 * 画中画准备停止
 */
- (void)pictureInPictureControllerWillStopPictureInPicture;

/**
 * 画中画已经停止
 */
- (void)pictureInPictureControllerDidStopPictureInPicture;

/**
 *  画中画返回app界面，后是否要停止
 */
- (BOOL)pictureInPictureIsPlaybackPaused;

@end



#endif /* AliPlayerPictureInPictureDelegate_h */
