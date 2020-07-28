//
//  AlivcEventReportDelegate.h
//  AlivcConanStatic
//
//  Created by lyz on 2018/11/12.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AlivcEventReporter;

@protocol AlivcEventReporterDelegate <NSObject>

@optional

/**
 event report error notify
 
 @param eventReport AlivcEventReport
 @param errorCode error code
 */
- (void)onAlivcEventReportError:(AlivcEventReporter *)eventReport
                      errorCode:(NSUInteger)errorCode;


/**
 鉴权信息即将失效，配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息

 @param eventReport AlivcEventReport
 @param afterTime 过期时长
 */
- (void)onAlivcEventReportStsWillExpireSoon:(AlivcEventReporter *)eventReport
                                  afterTime:(unsigned long)afterTime;


/**
 鉴权信息失效，配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息

 @param eventReport AlivcEventReport
 */
- (void)onAlivcEventReportStsExpired:(AlivcEventReporter *)eventReport;


- (void)onAlivcEventReport:(AlivcEventReporter *)eventReport
                    params:(NSMutableDictionary<NSString *, NSString *>*) params;
@end
