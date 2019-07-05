//
//  AMDDelegate.h
//  AliMediaDownloader
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AMDDelegate_h
#define AMDDelegate_h
@class AVPMediaInfo;
@class AVPErrorModel;

@class AliMediaDownloader;

#import <Foundation/Foundation.h>

@protocol AMDDelegate <NSObject>
@optional

/**
 @brief 下载准备完成事件回调
 @param downloader 下载downloader指针
 @param info 下载准备完成回调，@see AVPMediaInfo
 */
-(void)onPrepared:(AliMediaDownloader*)downloader mediaInfo:(AVPMediaInfo*)info;

/**
 @brief 错误代理回调
 @param downloader 下载downloader指针
 @param errorModel 播放器错误描述，参考AliVcPlayerErrorModel
 */
- (void)onError:(AliMediaDownloader*)downloader errorModel:(AVPErrorModel *)errorModel;

/**
 @brief 下载进度回调
 @param downloader 下载downloader指针
 @param percent 下载进度 0-100
 */
- (void)onDownloadingProgress:(AliMediaDownloader*)downloader percentage:(int)percent;

/**
 @brief 下载文件的处理进度回调
 @param downloader 下载downloader指针
 @param percent 下载进度 0-100
 */
- (void)onProcessingProgress:(AliMediaDownloader*)downloader percentage:(int)percent;

/**
 @brief 下载完成回调
 @param downloader 下载downloader指针
 */
- (void)onCompletion:(AliMediaDownloader*)downloader;

@end

#endif /* AMDDelegate_h */
