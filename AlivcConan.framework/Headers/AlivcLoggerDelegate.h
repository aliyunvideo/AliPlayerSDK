//
//  AlivcLogDelegate.h
//  AlivcConanStatic
//
//  Created by lyz on 2018/11/21.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AlivcLogger;

@protocol AlivcLoggerDelegate <NSObject>

@optional

/**
 创建日志文件成功
 
 @param alivcLoger alivcLoger
 @param path 文件路径
 */
- (void)onAlivcLogCreateLogFileSuccess:(AlivcLogger *)alivcLoger
                             localPath:(NSString *)path;


/**
 上传日志文件成功
 
 @param alivcLoger alivcLoger
 @param localpath 本地文件路径
 @param uploadpath 远端路径
 */
- (void)onAlivcLogUploadLogFileSuccess:(AlivcLogger *)alivcLoger
                             localPath:(NSString *)localpath
                            uploadPath:(NSString *)uploadpath;


/**
 日志鉴权信息初始化成功，初始化完成后才可上传日志

 @param alivcLoger alivcLoger
 */
- (void)onAlivcLogInitComplete:(AlivcLogger *)alivcLoger;


/**
 日志实例错误
 
 @param alivcLoger alivcLoger
 @param errorCode 错误码
 */
- (void)onAlivcLogError:(AlivcLogger *)alivcLoger
              errorCode:(NSUInteger)errorCode;


/**
 鉴权信息即将失效，配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息

 @param alivcLoger alivcLoger
 @param afterTime 失效时间
 */
- (void)onAlivcLogStsWillExpireSoon:(AlivcLogger *)alivcLoger
                          afterTime:(unsigned long)afterTime;


/**
 鉴权信息失效，配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息

 @param alivcLoger alivcLoger
 */
- (void)onAlivcLogStsExpired:(AlivcLogger *)alivcLoger;

@end
