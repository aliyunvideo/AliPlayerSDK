//
//  VidPlayerConfigGen.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef VidPlayerConfigGen_h
#define VidPlayerConfigGen_h

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface VidPlayerConfigGenerator : NSObject

/**
 @brief 设置预览时间
 @param previewTime 预览时间，单位为秒
 */
/****
 @brief Set the preview duration.
 @param previewTime The specified preview duration in seconds.
 */
-(void) setPreviewTime:(int)previewTime;

/**
 @brief HLS标准加密设置UriToken
 @param MtsHlsUriToken 字符串
 */
/****
 @brief Set a UriToken for HLS standard encryption.
 @param MtsHlsUriToken The UriToken.
 */
-(void) setHlsUriToken:(NSString*)MtsHlsUriToken;

/**
 @brief 添加vid的playerconfig参数
 @param key: 对应playerConfig中的参数名字
 @param value: 对应key参数的值
 */
/****
 @brief Add a playerconfig parameter for the specified VID.
 @param key: The name of the playerConfig parameter.
 @param value: The value of the parameter.
 */
-(void) addVidPlayerConfigByStringValue:(NSString*)key value:(NSString*)value;

/**
 @brief 添加vid的playerconfig参数
 @param key: 对应playerConfig中的参数名字
 @param value: 对应key参数的整形值
 */
/****
 @brief Add a playerconfig parameter for the specified VID.
 @param key: The name of the playerConfig parameter.
 @param value: The value of the parameter.
 */
-(void) addVidPlayerConfigByIntValue:(NSString*)key value:(int)value;


/**
 @brief 生成playerConfig
 */
/****
 @brief Generate playerConfig.
 */
-(NSString*) generatePlayerConfig;

@end

#endif /* VidPlayerConfigGen_h */
