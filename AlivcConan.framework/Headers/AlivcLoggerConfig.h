//
//  AlivcLogConfig.h
//  AlivcConanStatic
//
//  Created by OjisanC on 2018/5/20.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcConanConstans.h"

typedef NS_ENUM(NSInteger,AlivcLoggerLevel) {
    AlivcLoggerLevelDebug = 0,     /* 调试 */
    AlivcLoggerLevelInfo  = 1,     /* 信息 */
    AlivcLoggerLevelWarn  = 2,     /* 警告 */
    AlivcLoggerLevelError = 3,     /* 错误 */
    AlivcLoggerLevelFatal = 4,     /* 严重 */
};

typedef NS_OPTIONS(NSUInteger,AlivcLoggerMode) {
    AlivcLoggerModeLocalPrint  = 0x0001,   /* 本地打印 */
    AlivcLoggerModeLocalFile   = 0x0002,   /* 本地文件打印 */
};


typedef NS_ENUM(NSUInteger,AlivcLoggerUploadStrategy) {
    AlivcLoggerUploadStrategyAll   = 0,    /* 不限条件上传 */
    AlivcLoggerUploadStrategyWifi  = 1,    /* 仅WiFi下上传 */
};

OBJC_EXPORT
@interface AlivcLoggerConfig : NSObject


/**
 日志上传策略
 */
@property (nonatomic, assign) AlivcLoggerUploadStrategy strategy;

/**
 业务类型
 * 必选参数，默认为None
 */
@property (nonatomic, assign) AlivcConanBusinessType businessType;


/**
 是否开启外部鉴权
 * 默认 : NO 不开启
 * 若开启外部鉴权，下列的可选参数必填
 */
@property (nonatomic, assign) BOOL useExternalAuth;


/**
 OSS服务 endPoint
 * 可选参数
 */
@property (nonatomic, copy) NSString *endPoint;


/**
 OSS服务 bucket
 * 可选参数
 */
@property (nonatomic, copy) NSString *bucket;


/**
 OSS服务 accessKey
 * 可选参数
 */
@property (nonatomic, copy) NSString *accessKey;


/**
 OSS服务 secretKey
 * 可选参数
 */
@property (nonatomic, copy) NSString *secretKey;


/**
 OSS服务 securityToken
 * 可选参数
 */
@property (nonatomic, copy) NSString *securityToken;


/**
 OSS服务 strExpireTime
 * 可选参数
 */
@property (nonatomic, copy) NSString *expireTime;


@end

