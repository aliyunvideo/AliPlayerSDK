//
//  AlivcConanConstans.h
//  AlivcConanStatic
//
//  Created by lyz on 2018/11/20.
//  Copyright © 2018年 Aliyun. All rights reserved.
//


#import <Foundation/Foundation.h>


// SDK Version
extern NSString * const AlivcConanSDKVersion;


// BusinessType
typedef NS_ENUM(NSUInteger, AlivcConanBusinessType) {
    AlivcConanBusinessNone      = 0,     /* 无 */
    AlivcConanBusinessSvideo    = 1,     /* 短视频 */
    AlivcConanBusinessPusher    = 2,     /* 推流 */
    AlivcConanBusinessPlayer    = 3,     /* 播放器 */
    AlivcConanBusinessIlive     = 4,     /* 互动直播 */
    AlivcConanBusinessWboard    = 5,     /* 白板 */
};
