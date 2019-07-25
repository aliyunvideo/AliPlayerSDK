//
//  AVPSource.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018年 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVPSource_h
#define AVPSource_h

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface AVPSource : NSObject

/**
 @brief 封面地址
 */
@property (nonatomic, copy) NSString* coverURL;

/**
 @brief 视频标题
 */
@property (nonatomic, copy) NSString* title;

/**
 @brief 视频清晰度
 */
@property (nonatomic, copy) NSString* quality;

@end


OBJC_EXPORT
@interface AVPUrlSource : AVPSource

/**
 @brief init AVPUrlSource with url
 @param url video url address
 */
- (instancetype) urlWithString:(NSString*)url;

/**
 @brief init AVPUrlSource with filepath
 @param url file path
 */
- (instancetype) fileURLWithPath:(NSString*)url;

/**
 @brief player url
 */
@property (nonatomic, copy) NSURL* playerUrl;

@end

OBJC_EXPORT
@interface AVPVidStsSource : AVPSource

/**
 @brief 用vid和sts来播放视频，临时AccessKeyId、AccessKeySecret和SecurityToken：开启RAM授权，并通过STS授权系统提供的OpenAPI或SDK获取的AccessKeyId、AccessKeySecret和SecurityToken，用于播放和下载请求参数明细：https://help.aliyun.com/document_detail/28788.html?spm=5176.doc28787.6.706.2G5SLS
 @param vid 视频播放的vid标识
 @param accessKeyId 用户sts的accessKey ID
 @param accessKeySecret 用户sts的accessKey secret
 @param securityToken 用户sts的token信息
 @param region 用户sts的region信息
 */
- (instancetype)initWithVid:(NSString *)vid
                accessKeyId:(NSString *)accessKeyId
            accessKeySecret:(NSString *)accessKeySecret
              securityToken:(NSString *)securityToken
                     region:(NSString *)region;

- (instancetype)initWithVid:(NSString *)vid
                accessKeyId:(NSString *)accessKeyId
            accessKeySecret:(NSString *)accessKeySecret
              securityToken:(NSString *)securityToken
                     region:(NSString *)region
                playConfig:(NSString *)playConfig;

- (instancetype)initWithVid:(NSString *)vid
                accessKeyId:(NSString *)accessKeyId
            accessKeySecret:(NSString *)accessKeySecret
              securityToken:(NSString *)securityToken
                     region:(NSString *)region
                     format:(NSString *)format
                 playConfig:(NSString *)playConfig;

/**
 @brief vid
 */
@property (nonatomic, copy) NSString* vid;

/**
 @brief accessKeyId
 */
@property (nonatomic, copy) NSString* accessKeyId;

/**
 @brief accessKeySecret
 */
@property (nonatomic, copy) NSString* accessKeySecret;

/**
 @brief securityToken
 */
@property (nonatomic, copy) NSString* securityToken;

/**
 @brief region
 */
@property (nonatomic, copy) NSString* region;

/**
 @brief playConfig
 */
@property (nonatomic, copy) NSString* playConfig;

/**
 @brief format,default is nil, value is "mp4|mp3|flv|m3u8"
 */
@property (nonatomic, copy) NSString* format;

@end

OBJC_EXPORT
@interface AVPVidAuthSource : AVPSource

- (instancetype)initWithVid:(NSString *)vid
                   playAuth:(NSString *)playAuth
                     region:(NSString *)region;

- (instancetype)initWithVid:(NSString *)vid
        playAuth:(NSString *)playAuth
          region:(NSString *)region
                playConfig:(NSString *)playConfig;

- (instancetype)initWithVid:(NSString *)vid
                   playAuth:(NSString *)playAuth
                     region:(NSString *)region
                     format:(NSString *)format
                 playConfig:(NSString *)playConfig;

/**
 @brief vid
 */
@property (nonatomic, copy) NSString* vid;

/**
 @brief playAuth
 */
@property (nonatomic, copy) NSString* playAuth;

/**
 @brief region
 */
@property (nonatomic, copy) NSString* region;

/**
 @brief playConfig
 */
@property (nonatomic, copy) NSString* playConfig;

/**
 @brief format,default is nil, value is "mp4|mp3|flv|m3u8"
 */
@property (nonatomic, copy) NSString* format;

@end

OBJC_EXPORT
@interface AVPVidMpsSource : AVPSource

/**
 @brief 用vid和MPS信息来播放视频，视频转码服务用户使用播放方式。部分参数参考:https://help.aliyun.com/document_detail/53522.html?spm=5176.doc53534.2.5.mhSfOh
 @param vid 视频播放的vid标识
 @param accId 用户sts的accessKey ID
 @param accSecret 用户sts的accessKey secret
 @param stsToken 用户sts的token信息
 @param authInfo 用户authInfo信息
 @param region 用户region信息
 @param playDomain 用户playDomain信息
 @param mtsHlsUriToken 用户mtsHlsUriToken信息
 */
- (instancetype)initWithVid:(NSString*)vid
                 accId:(NSString *)accId
             accSecret:(NSString*)accSecret
              stsToken:(NSString*)stsToken
              authInfo:(NSString*)authInfo
                region:(NSString*)region
            playDomain:(NSString*)playDomain
        mtsHlsUriToken:(NSString*)mtsHlsUriToken;

/**
 @brief vid
 */
@property (nonatomic, copy) NSString* vid;

/**
 @brief accId
 */
@property (nonatomic, copy) NSString* accId;

/**
 @brief accSecret
 */
@property (nonatomic, copy) NSString* accSecret;

/**
 @brief stsToken
 */
@property (nonatomic, copy) NSString* stsToken;

/**
 @brief authInfo
 */
@property (nonatomic, copy) NSString* authInfo;

/**
 @brief region
 */
@property (nonatomic, copy) NSString* region;

/**
 @brief playDomain
 */
@property (nonatomic, copy) NSString* playDomain;

/**
 @brief mtsHlsUriToken
 */
@property (nonatomic, copy) NSString* mtsHlsUriToken;

@end

#endif /* AVPSource_h */
