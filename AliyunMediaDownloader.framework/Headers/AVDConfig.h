//
//  AVDConfig.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVDConfig_h
#define AVDConfig_h

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface AVDConfig : NSObject

/**
 @brief 最大超时时间 默认15000毫秒
 */
@property (nonatomic, assign) int timeoutMs;

/**
 @brief 最大连接超时时间 默认5000毫秒
 */
@property (nonatomic, assign) int connnectTimoutMs;

/**
 @brief 请求referer
 */
@property (nonatomic, copy) NSString *referer;

/**
 @brief user Agent
 */
@property (nonatomic, copy) NSString *userAgent;

/**
 @brief httpProxy代理
 */
@property (nonatomic, copy) NSString *httpProxy;

@end

#endif /* AVDConfig_h */
