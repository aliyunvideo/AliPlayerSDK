//
//  AliPlayerGlobalSettings.h
//  AliPlayerGlobalSettings
//
//  Created by huang_jiafa on 2020/04/09.
//  Copyright © 2020 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVPDef.h"

OBJC_EXPORT
@interface AliPlayerGlobalSettings : NSObject

/**
 @brief 设置域名对应的解析ip
 @param host 域名，需指定端口（http默认端口80，https默认端口443）。例如player.alicdn.com:443
 @param ip 相应的ip，设置为空字符串清空设定。
 */
/****
 @brief Set a DNS ip to resolve the host.
 @param host The host. Need to specify the port (http defualt port is 80，https default port is 443). E.g player.alicdn.com:443
 @param ip The ip address, set as empty string to clear the setting.
 */
+(void)setDNSResolve:(NSString *)host ip:(NSString *)ip;

/**
 @brief 设置解析ip类型
 @param type 解析ip的类型
 */
/****
 @brief Set a IP type when  resolve the host.
 @param type The IP type.
 */
+(void)setIpResolveType:(AVPIpResolveType)type;


/**
 @brief 设置fairPlay的用户证书id, 每次设置必须在同一个线程，否则无法更新
 @param certID 用户证书id
 */
/****
 @brief Set the .fairPlay certID, update the certID must use the thread first set
 @param type The IP type.
 */
+(void)setFairPlayCertID:(NSString *)certID;

/**
 @brief 设置是否使能硬件提供的音频变速播放能力，关闭后则使用软件实现音频的倍速播放，pcm回调数据的格式和此设置关联,如果修改，请在同一个线程操作,默认打开
 */
/****
 @brief enable/disable hardware audio tempo, player will use soft ware tempo filter when disabled, and it will affect the pcm data that from audio rending callback, it only can be reset in the same thread, enable by default.
 */
+ (void)enableHWAduioTempo:(bool)enable;


/**
 @brief 强制音频渲染器采用指定的格式进行渲染，如果设定的格式设备不支持，则无效，无效值将被忽略，使用默认值；pcm回调数据的格式和此设置关联,如果修改，请在同一个线程操作,默认关闭
 @param force 打开/关闭 强制设置
 @param fmt  设置pcm的格式，目前只支持s16，16位有符号整数
 @param channels 设置pcm的声道数，有效值 1~8
 @param sample_rate 设置pcm的采样率，有效值 1～48000
 */
/****
 @brief force audio render use the particular format,the value will no effect when the format not supported by device，the out range value will be ignored，and use the default value;
 and it will affect the pcm data that from audio rending callback, it only can be reset in the same thread, disabled by default.

 @param force enable/disable
 @param fmt the pcm format, only support s16 for now, signed integer with 16 bits
 @param channels the pcm channels， available range 1～8
 @param sample_rate set the pcm sample rate， available range 1～48000
 */

+ (void)forceAudioRendingFormat:(bool)force fmt:(NSString *)fmt channels:(int)channels sample_rate:(int)sample_rate;

+ (void)enableLocalCache:(bool)enable maxBufferMemoryKB:(int)maxBufferMemoryKB localCacheDir:(NSString *)localCacheDir;

@end
