//
//  AVPMediaInfo.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVPMediaInfo_h
#define AVPMediaInfo_h

#import <Foundation/Foundation.h>

const static int SELECT_AVPTRACK_TYPE_VIDEO_AUTO = -1;

/**
 @brief track type
 * AVPTRACK_TYPE_VIDEO: video track
 * AVPTRACK_TYPE_AUDIO: audio track
 * AVPTRACK_TYPE_SUBTITLE: subtitle track
 * AVPTRACK_TYPE_MIXED: have auido and video info in this track
 */
typedef enum AVPTrackType: NSUInteger {
    AVPTRACK_TYPE_VIDEO,
    AVPTRACK_TYPE_AUDIO,
    AVPTRACK_TYPE_SUBTITLE,
    AVPTRACK_TYPE_SAAS_VOD,//track from vod
} AVPTrackType;

OBJC_EXPORT
@interface AVPTrackInfo : NSObject

/**
 @brief track type @see AVPTrackType
 */
@property (nonatomic, assign) AVPTrackType trackType;

/**
 @brief vod format
 */
@property (nonatomic, copy) NSString* vodFormat;

/**
 @brief track index
 */
@property (nonatomic, assign) int trackIndex;

/**
 @brief track definition, only meaningful if the trackType is AVPTRACK_TYPE_SAAS_VOD
 */
@property (nonatomic, copy) NSString* trackDefinition;

/**
 @brief vod file size, only meaningful if the trackType is AVPTRACK_TYPE_SAAS_VOD
 */
@property (nonatomic, assign) int vodFileSize;

/**
 @brief vod play URL, only meaningful if the trackType is AVPTRACK_TYPE_SAAS_VOD
 */
@property (nonatomic, copy) NSString* vodPlayUrl;

/**
 @brief waterMark URL, only meaningful if the trackType is AVPTRACK_TYPE_SAAS_VOD
 */
@property (nonatomic, copy) NSString* waterMarkUrl;

/**
 @brief video width, only meaningful if the trackType is AVPTRACK_TYPE_VIDEO
 */
@property (nonatomic, assign) int videoWidth;

/**
 @brief video height, only meaningful if the trackType is AVPTRACK_TYPE_VIDEO
 */
@property (nonatomic, assign) int videoHeight;

/**
 @brief bitrate, only meaningful if the trackType is AVPTRACK_TYPE_VIDEO
 */
@property (nonatomic, assign) int trackBitrate;

/**
 @brief the number of audio channel, only meaningful if the trackType is AVPTRACK_TYPE_AUDIO
 */
@property (nonatomic, assign) int audioChannels;

/**
 @brief audio samplerate, only meaningful if the trackType is AVPTRACK_TYPE_AUDIO
 */
@property (nonatomic, assign) int audioSamplerate;

/**
 @brief audio sampleFormat, only meaningful if the trackType is AVPTRACK_TYPE_AUDIO
 */
@property (nonatomic, assign) int audioSampleFormat;

/**
 @brief audio Language, only meaningful if the trackType is AVPTRACK_TYPE_AUDIO
 */
@property (nonatomic, copy) NSString* audioLanguage;

/**
 @brief subtitle Language, only meaningful if the trackType is AVPTRACK_TYPE_SUBTITLE
 */
@property (nonatomic, copy) NSString* subtitleLanguage;


@end


OBJC_EXPORT
@interface AVPThumbnailInfo : NSObject

/**
 @brief thumbnail URL
 */
@property (nonatomic, copy) NSString* URL;

@end


OBJC_EXPORT
@interface AVPMediaInfo : NSObject

/**
 @brief media title
 */
@property (nonatomic, copy) NSString* title;

/**
 @brief media cover url
 */
@property (nonatomic, copy) NSString* coverURL;

/**
 @brief media type
 * video audio video|audio
 */
@property (nonatomic, copy) NSString* mediaType;

/**
 @brief media status
 */
@property (nonatomic, copy) NSString* status;

/**
 @brief media duration
 * 单位是秒
 */
/****
 @brief media duration
 * Unit: seconds.
 */
@property (nonatomic, assign) int duration;

/**
 @brief media transcodeMode
 *转码类型，取值：FastTranscode（上传完成即转码，且转码完成才能播放），NoTranscode（上传完成不转码，且立即能播放），默认取值FastTranscode
 */
/****
 @brief media transcodeMode
 *Transcoding type. Valid values: FastTranscode and NoTranscode. FastTranscode: Transcode the content immediately after it is uploaded. Only transcoded content can be played. NoTranscode: Do not transcode the content after it is uploaded. Content can be played without transcoding. Default: FastTranscode.
 */
@property (nonatomic, copy) NSString* transcodeMode;

/**
 @brief thumbnails in media info
 */
@property (nonatomic, strong) NSArray<AVPThumbnailInfo*>* thumbnails;

/**
 @brief tracks in media info
 */
@property (nonatomic, strong) NSArray<AVPTrackInfo*>* tracks;

@end

#endif /* AVPMediaInfo_h */
