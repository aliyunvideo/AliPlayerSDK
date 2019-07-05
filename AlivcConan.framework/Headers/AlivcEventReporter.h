//
//  AlivcEventReport.h
//  AlivcConanStatic
//
//  Created by OjisanC on 2018/5/18.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcEventReporterConfig.h"


@protocol AlivcEventReporterDelegate;

OBJC_EXPORT
@interface AlivcEventReporter : NSObject


/**
 event report delegate
 */
@property (nonatomic, weak) id<AlivcEventReporterDelegate> delegate;


/**
 init
 
 @param config AlivcEventReportConfig
 @return AlivcEventReport
 */
- (instancetype)initWithConfig:(AlivcEventReporterConfig *)config;


/**
 获取eventReportId，通过此Id可实例化crash采集和c++的eventReport

 @return eventReportId
 */
- (long long)getEventReportId;


/**
 release
 */
- (void)destroy;


/**
 重新设置SLS鉴权信息，使用外部鉴权时鉴权到期需要重新设置

 @param accessKey accessKey
 @param secretKey secretKey
 @param securityToken securityToken
 @return 0:success others:failed
 */
- (int)resetAcessTokenInfoWithAccessKey:(NSString *)accessKey
                              secretKey:(NSString *)secretKey
                          securityToken:(NSString *)securityToken
                             expireTime:(NSString *)expireTime;


/**
 发送埋点事件
 
 @param eventId eventId
 @param params params
 @return 0:success others:failed
 */
- (int)sendEvent:(int)eventId params:(NSDictionary *)params;


/**
 发送周期性埋点事件

 @return 0:success others:failed
 */
- (int)sendCyclistEvent;


/**
 发送全局单次上报事件

 @return 0:success others:failed
 */
- (int)sendOnceEvent;



/***** 业务参数(需要从业务SDK方获取),以下参数如果不设置则不上报 *****/


/**
 设置buildId commitId字段

 @param idString buildId commitId的组合字段
 @remark 此参数会添加到一次性上报参数内，如需上报此参数，则必须在sendOnceEvent之前调用
 */
- (void)setBuildIdCommitIdString:(NSString *)idString;

/**
 设置业务SDK版本号
 
 @param sdkVersion sdk版本号
 */
- (void)setSDKVersion:(NSString *)sdkVersion;


/**
 设置子模块名称
 
 @param module module
 */
- (void)setModuleName:(NSString *)module;


/**
 刷新sessionId，sessionId由Conan内部生成，业务SDK只负责刷新时机
 @warn:短视频SDK不使用此接口
 @return 新生成的sessionId
 */
- (NSString *)refreshSessionId;

/**
 设置sessionId

 @param sessionId sessionId
 */
- (void)setSessionId:(NSString *)sessionId;


/**
 更新TraceId

 @param traceId traceId
 */
- (void)updateTraceId:(NSString *)traceId;


/**
 更新userId

 @param userId userId
 */
- (void)updateUserId:(NSString *)userId;


/**
 更新roomId

 @param roomId roomId
 */
- (void)updateRoomId:(NSString *)roomId;


/**
 更新videoUrl

 @param videoUrl videoUrl
 */
- (void)updateVideoUrl:(NSString *)videoUrl;


/**
 更新videoType

 @param videoType 播放器类型
 */
- (void)updateVideoType:(NSString *)videoType;



/**
 更新Server环境信息

 @param environmentType 环境参数
 */
- (void)updateServerType:(AlivcConanEnvironmentType)environmentType;
    

/**
 更新Aliyun 控制台appid
 
 @param aliyunAppId 控制台appid
 */
- (void)updateAliyunAppId:(NSString *)aliyunAppId;
    

/**
 更新角色信息
 
 @param role 角色信息
 */
- (void)updateRole:(NSString *)role;

/*******************************************************/

@end

