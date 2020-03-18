//
//  AlivcLog.h
//  AlivcConanStatic
//
//  Created by OjisanC on 2018/5/20.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcLoggerConfig.h"

@class AlivcLoggerConfig;
@protocol AlivcLoggerDelegate;

OBJC_EXPORT
@interface AlivcLogger : NSObject


/**
 log delegate
 */
@property (nonatomic, weak) id<AlivcLoggerDelegate> delegate;


/**
 init

 @param config logConfig
 @return self
 */
- (instancetype)initWithLogConfig:(AlivcLoggerConfig *)config;


/**
 release
 */
- (void)destroy;


/**
 获取logId，通过此Id可以实例化crash采集和c++的log模块

 @return logID
 */
- (long long)getLogId;


/**
 日志上传成功后是否删除本地文件
 
 @param enable YES:移除 NO:不移除 [默认 : NO]
 */
- (void)removeLogFileAfterUpload:(BOOL)enable;


/**
 设置文件大小上限
 
 @param size 文件大小 [默认 : -1(无上限)]
 */
- (void)setFileMaxSize:(NSUInteger)size;

/**
 设置traceId

 @param traceId traceId
 */
- (void)setTraceId:(NSString *)traceId;


/**
 设置日志模式
 
 @param mode 日志模式 [默认 : AlivcLogModeLocalPrint]
 */
- (void)setLogMode:(AlivcLoggerMode)mode;


/**
 设置日志等级
 
 @param level 日志等级 (默认Debug)
 */
- (void)setLogLevel:(AlivcLoggerLevel)level;


/**
 关闭日志
 */
- (void)disableLog;


/**
 重置OSS鉴权信息，使用外部鉴权时鉴权到期需要重新设置

 @param accessKey accessKey
 @param secretKey secretKey
 @param securityToken securityToken
 @return 0:success other:fail
 */
- (int)resetAcessTokenInfoWithKey:(NSString *)accessKey
                        secretKey:(NSString *)secretKey
                    securityToken:(NSString *)securityToken
                       expireTime:(NSString *)expireTime;


/**
 设置日志文件保存路径
 
 @param path 文件路径
 @remark 当日志模式包含LocalFile时，需要在首次打印日志前设置缓存路径，后续日志文件将保存在缓存路径
 @remark 若未设置缓存路径，默认在sandbox-Cache路径下输出日志文件
 */
- (void)setFilePath:(NSString *)path;


/**
 开始上传日志文件

 @param filePath 指定需要上传的文件夹路径
 @remark filePath可以传nil，filePath为nil时上传默认log日志路径下的文件
 */
- (void)uploadFile:(NSString *)filePath;


// debug 日志
- (void)debug:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

- (void)debug:(NSString *)tag format:(NSString *)format, ... NS_FORMAT_FUNCTION(2, 3);

// info 日志
- (void)info:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

- (void)info:(NSString *)tag format:(NSString *)format, ... NS_FORMAT_FUNCTION(2, 3);

// warn 日志
- (void)warn:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

- (void)warn:(NSString *)tag format:(NSString *)format, ... NS_FORMAT_FUNCTION(2, 3);

// error 日志
- (void)error:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

- (void)error:(NSString *)tag format:(NSString *)format, ... NS_FORMAT_FUNCTION(2, 3);

@end

