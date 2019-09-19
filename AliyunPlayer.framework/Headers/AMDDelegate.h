//
//  AMDDelegate.h
//  AliMediaDownloader
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
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
/****
 @brief Download preparation completion callback.
 @param downloader Downloader pointer.
 @param info Download preparation completion callback. @see AVPMediaInfo
 */
-(void)onPrepared:(AliMediaDownloader*)downloader mediaInfo:(AVPMediaInfo*)info;

/**
 @brief 错误代理回调
 @param downloader 下载downloader指针
 @param errorModel 播放器错误描述，参考AliVcPlayerErrorModel
 */
/****
 @brief Proxy error callback.
 @param downloader Downloader pointer.
 @param errorModel Player error description. See AliVcPlayerErrorModel
 */
- (void)onError:(AliMediaDownloader*)downloader errorModel:(AVPErrorModel *)errorModel;

/**
 @brief 下载进度回调
 @param downloader 下载downloader指针
 @param percent 下载进度 0-100
 */
/****
 @brief Download progress callback.
 @param downloader Downloader pointer.
 @param percent Download progress: 0 to 100.
 */
- (void)onDownloadingProgress:(AliMediaDownloader*)downloader percentage:(int)percent;

/**
 @brief 下载文件的处理进度回调
 @param downloader 下载downloader指针
 @param percent 下载进度 0-100
 */
/****
 @brief Downloaded file processing progress callback.
 @param downloader Downloader pointer.
 @param percent Processing progress: 0 to 100.
 */
- (void)onProcessingProgress:(AliMediaDownloader*)downloader percentage:(int)percent;

/**
 @brief 下载完成回调
 @param downloader 下载downloader指针
 */
/****
 @brief Download completion callback.
 @param downloader Downloader pointer.
 */
- (void)onCompletion:(AliMediaDownloader*)downloader;

@end

#endif /* AMDDelegate_h */
