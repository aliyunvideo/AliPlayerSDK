//
//  VidPlayerConfigGen.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
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
-(void) setPreviewTime:(int)previewTime;

/**
 @brief HLS标准加密设置UriToken
 @param MtsHlsUriToken 字符串
 */
-(void) setHlsUriToken:(NSString*)MtsHlsUriToken;

/**
 @brief 添加vid的playerconfig参数
 @param key: 对应playerConfig中的参数名字
 @param value: 对应key参数的值
 */
-(void) addVidPlayerConfigByStringValue:(NSString*)key value:(NSString*)value;

/**
 @brief 添加vid的playerconfig参数
 @param key: 对应playerConfig中的参数名字
 @param value: 对应key参数的整形值
 */
-(void) addVidPlayerConfigByIntValue:(NSString*)key value:(int)value;


/**
 @brief 生成playerConfig
 */
-(NSString*) generatePlayerConfig;

@end

#endif /* VidPlayerConfigGen_h */
