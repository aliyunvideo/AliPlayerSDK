//
//  AliPlayerGlobalSettings.h
//  AliPlayerGlobalSettings
//
//  Created by huang_jiafa on 2020/04/09.
//  Copyright © 2020 com.alibaba.AliyunPlayer. All rights reserved.
//

#import "AVPDef.h"
#import <Foundation/Foundation.h>

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
 @brief 设置是否使用http2。
 @param use
 */
/****
 @brief Set use http2 or not。
 @param use
 */
+ (void)setUseHttp2:(bool)use;

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

/**
  @brief 开启本地缓存，开启之后，就会缓存到本地文件中。
  @param enable true：开启本地缓存。false：关闭。默认关闭。
  @param maxBufferMemoryKB 设置单个源的最大内存占用大小。单位KB
  @param localCacheDir 本地缓存的文件目录，绝对路径
 */
/****
 @brief Enable local cache. When enabled, it will be cached in local files.
 @param enable true: enables the local cache. false: disable. This function is disabled by default.
 @param maxBufferMemoryKB Set the maximum memory size for a single source. Unit is KB
 @param localCacheDir Directory of files cached locally, absolute path
*/
+ (void)enableLocalCache:(bool)enable maxBufferMemoryKB:(int)maxBufferMemoryKB localCacheDir:(NSString *)localCacheDir;

/**
 @brief 本地缓存文件自动清理相关的设置
 @param expireMin 缓存多久过期：单位分钟，默认值30天，过期的缓存不管容量如何，都会在清理时淘汰掉；
 @param maxCapacityMB 最大缓存容量：单位兆，默认值20GB，在清理时，如果缓存总大小超过此大小，会以cacheItem为粒度，按缓存的最后时间排序，一个一个淘汰掉一些缓存，直到小于等于最大缓存容量；
 @param freeStorageMB 磁盘最小空余容量：单位兆，默认值0，在清理时，同最大缓存容量，如果当前磁盘容量小于该值，也会按规则一个一个淘汰掉一些缓存，直到freeStorage大于等于该值或者所有缓存都被干掉；
 */
/****
 @brief Settings related to automatic clearing of local cache files
 @param expireMin How long the cache expires: the unit is minute. The default value is 30 days.
 @param maxCapacityMB maximum cache capacity: in megabytes. The default value is 20GB. If the total cache size exceeds this size, some caches are discarded one by one in the cacheItem granularity until they are smaller than or equal to the maximum cache capacity.
 @param freeStorageMB Minimum free disk capacity: in megabytes. The default value is 0. If the current disk capacity is less than this value, the freeStorage will be eliminated one by one until the freeStorage is greater than or equal to this value or all caches are eliminated.
*/
+ (void)setCacheFileClearConfig:(int64_t)expireMin maxCapacityMB:(int64_t)maxCapacityMB freeStorageMB:(int64_t)freeStorageMB;

/**
 @brief 回调方法
 @param url 视频url
 @return hash值，必须要保证每个url都不一样
   */
/****
 @brief callback
 @param url the loaded URL
 @return the hash value . Ensure that each URL is different.
 */
typedef NSString *(*CaheUrlHashCallback)(NSString *url);

/**
 @brief  设置加载url的hash值回调。如果不设置，SDK使用md5算法。
 */
/****
 @brief Sets the hash callback to load the URL. If this parameter is not set, the SDK uses md5 algorithm.
 */
+ (void)setCacheUrlHashCallback:(CaheUrlHashCallback)callback;

/**
 @brief 是否开启httpDNS。默认不开启。
 @param enable
 */
/****
 @brief enable httpDNS. Default is disabled.
 @param enable
 */
+ (void)enableHttpDns:(BOOL)enable;


+ (void) clearCaches;

@end
