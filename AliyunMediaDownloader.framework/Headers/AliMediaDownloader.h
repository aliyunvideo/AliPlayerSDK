//
//  AliMediaDownloader.h
//  AliMediaDownloader
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
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
+(int) deleteFile:(NSString *)saveDir vid:(NSString *)vid format:(NSString *)format index:(int)index;

/**
 @brief 初始化下载对象
 */
- (instancetype)init;

/**
 @brief 销毁下载对象
 */
- (void)destroy;

/**
 @brief 使用AVPVidStsSource准备播放
 @param source vid sts的播放方式
 */
- (void) prepareWithVid:(AVPVidStsSource*)source;

/**
 @brief 鉴权过期，更新AVPVidStsSource信息，
 @param source vid sts的信息
 */
- (void) updateWithVid:(AVPVidStsSource*)source;

/**
 @brief 使用AVPVidAuthSource准备播放
 @param source vid playAuth的播放方式
 */
- (void) prepareWithPlayAuth:(AVPVidAuthSource*)source;

/**
 @brief 设置下载的保存路径
 @param dir 保存文件夹
 */
- (void) setSaveDirectory:(NSString*)dir;

/**
 @brief 开始下载
 */
- (void) start;

/**
 @brief 停止下载
 */
- (void) stop;

/**
 @brief 删除下载文件
 */
- (void)deleteFile;

/**
 @brief 获取下载config
 */
- (AVDConfig*) getConfig;

/**
 @brief 设置下载config
 */
- (void) setConfig:(AVDConfig*)config;

/**
 @brief 设置下载的trackIndex
 @param trackIndex 从prepare回调中可以获取所有index
 */
- (void) selectTrack:(int)trackIndex;

/**
 @brief 设置转换播放的url的回调函数，一般用于p2p中的url地址转换
 @param callback 回调函数指针
 */
- (void) setPlayUrlConvertCallback:(PlayURLConverCallback)callback;

/**
 @brief 设置代理，参考AMDDelegate
 */
@property (nonatomic, weak) id<AMDDelegate> delegate;

/**
 @brief 获取SDK版本号信息
 */
+ (NSString*) getSDKVersion;

/**
 @brief 是否打开log输出
 */
@property(nonatomic) BOOL enableLog;

/**
 @brief 获取下载之后的文件路径
 */
@property (nonatomic, readonly) NSString* downloadedFilePath;

@end

