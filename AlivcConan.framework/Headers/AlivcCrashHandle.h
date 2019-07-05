//
//  AlivcCrashHandle.h
//  AlivcConanStatic
//
//  Created by lyz on 2018/11/10.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AlivcCrashConfig;

OBJC_EXPORT
@interface AlivcCrashHandle : NSObject

/**
 单例

 @return self
 */
+ (instancetype)shareHandle;


/**
 生成独立的crash模块
 
 @param config config
 @return crash模块对应的Id，后续的增删操作均需要通过此Id进行
 @remark 一定要在实例化eventReport和log后使用，否则无法执行crash上报
 */
- (NSString *)createWithCrashConfig:(AlivcCrashConfig *)config;


/**
 移除crash模块，移除之后将不再执行crash上报

 @param crashId 需要移除的crashId
 */
- (void)releaseWithCrashId:(NSString *)crashId;


/**
 注册crash handler
 
 @remark : 注册之后即开启crash捕捉，此接口可重复调用
 */
- (void)registCrashHandler;


/**
 取消注册crash handler
 
 @remark : 取消注册之后结束crash捕捉
 @remark : 请先调用releaseWithCrashId接口，当所有crash模块均移除的时候，才会彻底注销crashHandler
 */
- (void)unRegistCrashHandler;


/**
 增加crashFilter字段

 @param crashId 需要增加的crashId
 @param filter filter字段
 */
- (void)addCrashFilter:(NSString *)crashId filter:(NSString *)filter;


/**
 移除crashFilter字段

 @param crashId 需要移除的crashId
 @param filter filter字段
 */
- (void)removeCrashFilter:(NSString *)crashId filter:(NSString *)filter;


/**
 更新traceId

 @param crashId 需要更新的crashId
 @param traceId traceId
 */
- (void)updateTraceId:(NSString *)crashId traceId:(NSString *)traceId;


/**
 添加自定义Info信息，info信息最终会写入crash文件中

 @param crashId 需要更新的crashId
 @param info info信息
 */
- (void)addCrashInfo:(NSString *)crashId info:(NSString *)info;


@end
