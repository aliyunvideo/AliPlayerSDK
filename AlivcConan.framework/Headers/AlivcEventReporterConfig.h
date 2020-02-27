//
//  AlivcEventReportConfig.h
//  AlivcConanStatic
//
//  Created by OjisanC on 2018/5/18.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcConanConstans.h"


// SDK环境
typedef NS_ENUM(NSUInteger, AlivcConanEnvironmentType) {
    AlivcConanEnvironmentNone       = 0,     /* 无 */
    AlivcConanEnvironmentDaily      = 1,     /* 日常 */
    AlivcConanEnvironmentPre        = 2,     /* 预发 */
    AlivcConanEnvironmentOnline     = 3,     /* 线上 */
};


/**
 埋点配置
 */
OBJC_EXPORT
@interface AlivcEventReporterConfig : NSObject

/**
 SLS服务 project name
 * 可选参数
 */
@property (nonatomic, copy) NSString *projectName;


/**
 SLS服务 log store name
 * 可选参数
 */
@property (nonatomic, copy) NSString *logStore;


/**
 SLS服务 endPoint
 * 可选参数
 */
@property (nonatomic, copy) NSString *endPoint;


/**
 SLS服务 accessKey
 * 可选参数
 */
@property (nonatomic, copy) NSString *accessKey;


/**
 SLS服务 secretKey
 * 可选参数
 */
@property (nonatomic, copy) NSString *secretKey;


/**
 SLS服务 securityToken
 * 可选参数
 */
@property (nonatomic, copy) NSString *securityToken;


/**
 SLS服务 strExpireTime
 * 可选参数
 */
@property (nonatomic, copy) NSString *strExpireTime;


/**
 是否开启外部鉴权
 * 默认 : NO 不开启
 * 若开启外部鉴权，上述可选参数必填
 */
@property (nonatomic, assign) BOOL useExternalAuth;


/**
 业务类型
 * 必选参数
 * 默认 : 默认为None
 */
@property (nonatomic, assign) AlivcConanBusinessType businessType;


/**
 柯南版本号
 * 只读
 */
@property (nonatomic, readonly) NSString *conanVersion;


@end

