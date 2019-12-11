//
//  AliMediaDownloader.h
//  AliMediaDownloader
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AliyunPlayer/AliyunPlayer.h>
#import "AVDConfig.h"

@class AVPVidStsSource;
@class AVPVidAuthSource;


OBJC_EXPORT
@interface AliMediaDownloader : NSObject

/**
 @brief 删除下载文件
 @param saveDir 文件保存路径
 @param vid     vid
 @param format  格式
 @param index   vid对应的下载索引
 */
/****
 @brief Delete a downloaded file.
 @param saveDir The path where the file is saved.
 @param vid     VID.
 @param format  Format.
 @param index   The download index corresponds to the VID.
 */
+(int) deleteFile:(NSString *)saveDir vid:(NSString *)vid format:(NSString *)format index:(int)index;

/**
 @brief 初始化下载对象
 */
/****
 @brief Intialize the download object.
 */
- (instancetype)init;

/**
 @brief 销毁下载对象
 */
/****
 @brief Delete the download object.
 */
- (void)destroy;

/**
 @brief 使用AVPVidStsSource准备播放
 @param source vid sts的播放方式
 */
/****
 @brief Use AVPVidStsSource to prepare for playback.
 @param source vid Play the media through VidSts.
 */
- (void) prepareWithVid:(AVPVidStsSource*)source;

/**
 @brief 鉴权过期，更新AVPVidStsSource信息，
 @param source vid sts的信息
 */
/****
 @brief Update the AVPVidStsSource information when the authentication expires.
 @param source vid STS information.
 */
- (void) updateWithVid:(AVPVidStsSource*)source;

/**
 @brief 使用AVPVidAuthSource准备播放
 @param source vid playAuth的播放方式
 */
/****
 @brief Use AVPVidAuthSource to prepare for playback.
 @param source vid Play the media through playAuth.
 */
- (void) prepareWithPlayAuth:(AVPVidAuthSource*)source;

/**
 @brief 鉴权过期，更新AVPVidAuthSource信息，
 @param source vid auth的信息
 */
/****
 @brief Update the AVPVidAuthSource information when the authentication expires.
 @param source vid Authentication information.
 */
- (void) updateWithPlayAuth:(AVPVidAuthSource*)source;

/**
 @brief 设置下载的保存路径
 @param dir 保存文件夹
 */
/****
 @brief Set a path to save the downloaded file.
 @param dir The specified path.
 */
- (void) setSaveDirectory:(NSString*)dir;

/**
 @brief 开始下载
 */
/****
 @brief Start downloading.
 */
- (void) start;

/**
 @brief 停止下载
 */
/****
 @brief Pause downloading.
 */
- (void) stop;

/**
 @brief 删除下载文件
 */
/****
 @brief Delete the downloaded file.
 */
- (void)deleteFile;

/**
 @brief 获取下载config
 */
/****
 @brief Query download config.
 */
- (AVDConfig*) getConfig;

/**
 @brief 设置下载config
 */
/****
 @brief Modify download config.
 */
- (void) setConfig:(AVDConfig*)config;

/**
 @brief 设置下载的trackIndex
 @param trackIndex 从prepare回调中可以获取所有index
 */
/****
 @brief Specify the indexes of the tracks to be downloaded.
 @param trackIndex Use the prepare callback to retrieve all track indexes.
 */
- (void) selectTrack:(int)trackIndex;

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
 @brief 设置代理，参考AMDDelegate
 */
/****
 @brief Set a proxy. See AMDDelegate.
 */
@property (nonatomic, weak) id<AMDDelegate> delegate;

/**
 @brief 获取SDK版本号信息
 */
/****
 @brief Query the SDK version.
 */
+ (NSString*) getSDKVersion;

/**
 @brief 获取下载之后的文件路径
 */
/****
 @brief Query the path of the downloaded file.
 */
@property (nonatomic, readonly) NSString* downloadedFilePath;

@end

