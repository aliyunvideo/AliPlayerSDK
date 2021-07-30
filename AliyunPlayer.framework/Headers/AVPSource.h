//
//  AVPSource.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVPSource_h
#define AVPSource_h

#import <Foundation/Foundation.h>

typedef int (^BitStreamReadCallbackBlock)(uint8_t *buffer, int size);

typedef long (^BitStreamSeekCallbackBlock)(long offset, int whence);

static const int SEEK_SIZE = 0x10000;

typedef NS_ENUM(NSUInteger, ENCRYPTION_TYPE) { ENCRYPTION_TYPE_NONE = 0, ENCRYPTION_TYPE_ALIVODENCRYPTION, ENCRYPTION_TYPE_FAIRPLAY };

OBJC_EXPORT
@interface AVPSource : NSObject

/**
 @brief 封面地址
 */
/****
 @brief The URL of the album cover.
 */
@property (nonatomic, copy) NSString* coverURL;

/**
 @brief 视频标题
 */
/****
 @brief The title of the video.
 */
@property (nonatomic, copy) NSString* title;

/**
 @brief 期望播放的清晰度
 */
/****
 @brief The preferred definition for playback.
 */
@property (nonatomic, copy) NSString* quality;

/**
 @brief 是否强制使用此清晰度。如果强制，则在没有对应清晰度的情况下播放不了。
 */
/****
 @brief Whether to force the player to play the media with the specified definition. If the media does not support the specified definition, then it cannot be played.
 */
@property (nonatomic, assign) BOOL forceQuality;

/**
 @brief 设置点播服务器返回的码率清晰度类型。例如："FD,LD,SD,HD,OD,2K,4K,SQ,HQ"。
 *      注意：如果类型为"AUTO"， 那么只会返回自适应码率流。
 */
@property (nonatomic, copy) NSString* definitions;

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

/**
 @brief cache file path, app may cache the beginning of remote mp4 file to local path,
 * set it to player to improve loading speed.
 */
@property (nonatomic, copy) NSString* cacheFile;

@property(nonatomic) uint64_t originSize;

@end


OBJC_EXPORT
@interface AVPBitStreamSource : AVPSource

@property(nonatomic, copy) BitStreamReadCallbackBlock mBitStreamReadCallbackBlock;

@property(nonatomic, copy) BitStreamSeekCallbackBlock mBitStreamSeekCallbackBlock;

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
/****
 @brief Play by VID and STS. Temporary AccessKey ID, AccessKey Secret, and token: Activate RAM, and use the API or SDK provided by STS to retrieve the AccessKey ID, AccessKey Secret, and token. Details about parameters in playback and download requests: https://help.aliyun.com/document_detail/28788.html?spm=5176.doc28787.6.706.2G5SLS
 @param vid The VID of the video.
 @param accessKeyId The AccessKey ID of the user.
 @param accessKeySecret The AccessKey Secret of the user.
 @param securityToken The token information of the user.
 @param region The region information of the user.
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
 @brief format,default is nil, value is "mp4,mp3,flv,m3u8"
 */
@property (nonatomic, copy) NSString* format;
/**
 @brief authTimeout
 */
@property (nonatomic, assign) long authTimeout;
/**
 @brief resultType
 */
@property (nonatomic, copy) NSString* resultType;
/**
 @brief reAuthInfo
 */
@property (nonatomic, copy) NSString* reAuthInfo;
/**
 @brief streamType
 */
@property (nonatomic, copy) NSString* streamType;
/**
 @brief outputType
 */
@property (nonatomic, copy) NSString* outputType;


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
 @brief format,default is nil, value is "mp4,mp3,flv,m3u8"
 */
@property (nonatomic, copy) NSString* format;
/**
 @brief authTimeout
 */
@property (nonatomic, assign) long authTimeout;
/**
 @brief resultType
 */
@property (nonatomic, copy) NSString* resultType;
/**
 @brief reAuthInfo
 */
@property (nonatomic, copy) NSString* reAuthInfo;
/**
 @brief streamType
 */
@property (nonatomic, copy) NSString* streamType;
/**
 @brief outputType
 */
@property (nonatomic, copy) NSString* outputType;

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
/****
 @brief Play by VID and MPS. This playback method is used by video transcoding service users. Reference for some of the parameters: https://help.aliyun.com/document_detail/53522.html?spm=5176.doc53534.2.5.mhSfOh
 @param vid The VID of the video.
 @param accId The AccessKey ID of the user.
 @param accSecret The AccessKey Secret of the user.
 @param stsToken The token information of the user.
 @param authInfo The authInfo of the user.
 @param region The region information of the user.
 @param playDomain The playDomain information of the user.
 @param mtsHlsUriToken The mtsHlsUriToken information of the user.
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

OBJC_EXPORT
@interface AVPLiveStsSource : AVPSource

- (instancetype)initWithUrl:(NSString *)url
                accessKeyId:(NSString *)accessKeyId
            accessKeySecret:(NSString *)accessKeySecret
              securityToken:(NSString *)securityToken
                     region:(NSString *)region
                     domain:(NSString *)domain
                        app:(NSString *)app
                     stream:(NSString *)stream
             encryptionType:(ENCRYPTION_TYPE)encryptionType;

/**
 @brief url
 */
@property (nonatomic, copy) NSString* url;

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
 @brief domain
 */
@property (nonatomic, copy) NSString* domain;

/**
 @brief app
 */
@property (nonatomic, copy) NSString* app;

/**
 @brief stream
 */
@property (nonatomic, copy) NSString* stream;

/**
 @brief encryptionType
 */
@property(assign) ENCRYPTION_TYPE encryptionType;

@end

#endif /* AVPSource_h */
