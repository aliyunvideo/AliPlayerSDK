//
//  AVPDelegate.h
//  AliPlayerSDK
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#ifndef AVPDelegate_h
#define AVPDelegate_h

@class AliPlayer;
@class AVPTrackInfo;

#import <Foundation/Foundation.h>
#import "AVPDef.h"

@protocol AVPDelegate <NSObject>
@optional

/**
 @brief 播放器事件回调
 @param player 播放器player指针
 @param eventType 播放器事件类型
 @see AVPEventType
 */
/****
 @brief Player event callback.
 @param player Player pointer.
 @param eventType Player event type.
 @see AVPEventType
 */
-(void)onPlayerEvent:(AliPlayer*)player eventType:(AVPEventType)eventType;

/**
 @brief 播放器事件回调
 @param player 播放器player指针
 @param eventWithString 播放器事件类型
 @param description 播放器事件说明
 @see AVPEventType
 */
/****
 @brief Player event callback.
 @param player Player pointer.
 @param eventWithString Player event type.
 @param description Player event description.
 @see AVPEventType
 */
-(void)onPlayerEvent:(AliPlayer*)player eventWithString:(AVPEventWithString)eventWithString description:(NSString *)description;

/**
 @brief 错误代理回调
 @param player 播放器player指针
 @param errorModel 播放器错误描述，参考AVPErrorModel
 @see AVPErrorModel
 */
/****
 @brief Proxy error callback.
 @param player Player pointer.
 @param errorModel Player error description. See AVPErrorModel.
 @see AVPErrorModel
 */
- (void)onError:(AliPlayer*)player errorModel:(AVPErrorModel *)errorModel;

/**
 @brief 视频大小变化回调
 @param player 播放器player指针
 @param width 视频宽度
 @param height 视频高度
 @param rotation 视频旋转角度
 */
/****
 @brief Video size change callback.
 @param player Player pointer.
 @param width Video width.
 @param height Video height.
 @param rotation Video rotate angle.
 */
- (void)onVideoSizeChanged:(AliPlayer*)player width:(int)width height:(int)height rotation:(int)rotation;

/**
 @brief 视频当前播放位置回调
 @param player 播放器player指针
 @param position 视频当前播放位置
 */
/****
 @brief Current playback position callback.
 @param player Player pointer.
 @param position Current playback position.
 */
- (void)onCurrentPositionUpdate:(AliPlayer*)player position:(int64_t)position;

/**
 @brief 视频当前播放内容对应的utc时间回调
 @param player 播放器player指针
 @param time utc时间
 */
/****
 @brief Current playback utc time callback.
 @param player Player pointer.
 @param position Current  utc time.
 */

- (void)onCurrentUtcTimeUpdate:(AliPlayer *)player time:(int64_t)time;

/**
 @brief 视频当前播放缓存命中回调
 @param player 播放器player指针
 @param size 文件大小
 */
/****
 @brief Current playback cached file size callback.
 @param player Player pointer.
 @param size file size.
 */
- (void)onLocalCacheLoaded:(AliPlayer *)player size:(int64_t)size;

/**
 @brief 视频缓存位置回调
 @param player 播放器player指针
 @param position 视频当前缓存位置
 */
/****
 @brief Current cache position callback.
 @param player Player pointer.
 @param position Current cache position.
 */
- (void)onBufferedPositionUpdate:(AliPlayer*)player position:(int64_t)position;

/**
 @brief 视频缓冲进度回调
 @param player 播放器player指针
 @param progress 缓存进度0-100
 */
/****
 @brief Buffer progress callback.
 @param player Player pointer.
 @param progress Buffer progress: from 0 to 100.
 */
- (void)onLoadingProgress:(AliPlayer*)player progress:(float)progress;


/**
 @brief 当前下载速度回调
 @param player 播放器player指针
 @param speed bits per second
 */
/****
 @brief current download speed callback.
 @param player Player pointer.
 @param speed bits per second.
 */

- (void)onCurrentDownloadSpeed:(AliPlayer *)player speed:(int64_t)speed;

/**
 @brief 获取track信息回调
 @param player 播放器player指针
 @param info track流信息数组
 @see AVPTrackInfo
 */
/****
 @brief Track information callback.
 @param player Player pointer.
 @param info An array of track information.
 @see AVPTrackInfo
 */
- (void)onTrackReady:(AliPlayer*)player info:(NSArray<AVPTrackInfo*>*)info;

/**
 @brief 选择希望播放的流
 @param player 播放器player指针
 @param info track流信息数组
 @see AVPTrackInfo
 */
- (int)onChooseTrackIndex:(AliPlayer *)player info:(NSArray<AVPTrackInfo *> *)info;

/**
 @brief track切换完成回调
 @param player 播放器player指针
 @param info 切换后的信息 参考AVPTrackInfo
 @see AVPTrackInfo
 */
/****
 @brief Track switchover completion callback.
 @param player Player pointer.
 @param info Track switchover completion information. See AVPTrackInfo.
 @see AVPTrackInfo
 */
- (void)onTrackChanged:(AliPlayer*)player info:(AVPTrackInfo*)info;

/**
 @brief 外挂字幕被添加
 @param player 播放器player指针
 @param index 字幕显示的索引号
 @param URL 字幕url
 */
/****
 @brief External subtitles have been added
 @param player Player pointer.
 @param trackIndex Subtitle index.
 @param URL subtitle url
 */
- (void)onSubtitleExtAdded:(AliPlayer*)player trackIndex:(int)trackIndex URL:(NSString *)URL;


/**
 @brief 字幕头信息回调，ass字幕，如果实现了此回调，则播放器不会渲染字幕，由调用者完成渲染，否则播放器自动完成字幕的渲染
 @param player 播放器player指针
 @param index 字幕显示的索引号
 @param header 头内容
 */
/****
 @brief subtitle header info callback,
        for ass, player will not render the subtitle when this is implemented by user
 @param player Player pointer.
 @param trackIndex Subtitle index.
 @param URL subtitle url
 */
- (void)onSubtitleHeader:(AliPlayer *)player trackIndex:(int)trackIndex Header:(NSString *)header;

/**
 @brief 字幕显示回调
 @param player 播放器player指针
 @param trackIndex 字幕流索引.
 @param subtitleID  字幕ID.
 @param subtitle 字幕显示的字符串
 */
/****
 @brief Show subtitle callback.
 @param player Player pointer.
 @param trackIndex Subtitle stream index.
 @param subtitleID Subtitle ID.
 @param subtitle Subtitle string.
 */
- (void)onSubtitleShow:(AliPlayer*)player trackIndex:(int)trackIndex subtitleID:(long)subtitleID subtitle:(NSString *)subtitle;

/**
 @brief 字幕隐藏回调
 @param player 播放器player指针
 @param trackIndex 字幕流索引.
 @param subtitleID  字幕ID.
 */
/****
 @brief Hide subtitle callback.
 @param player Player pointer.
 @param trackIndex Subtitle stream index.
 @param subtitleID Subtitle ID.
 */
- (void)onSubtitleHide:(AliPlayer*)player trackIndex:(int)trackIndex subtitleID:(long)subtitleID;

/**
 @brief 获取缩略图成功回调
 @param positionMs 指定的缩略图位置
 @param fromPos 此缩略图的开始位置
 @param toPos 此缩略图的结束位置
 @param image 缩图略图像指针,对于mac是NSImage，iOS平台是UIImage指针
 */
/****
 @brief Thumbnail image retrieval success callback.
 @param positionMs The specified thumbnail image position.
 @param fromPos The initial position of the thumbnail image.
 @param toPos The end position of the thumbnail image.
 @param image Thumbnail image pointer. Mac: NSImage. iOS: UIImage.
 */
- (void)onGetThumbnailSuc:(int64_t)positionMs fromPos:(int64_t)fromPos toPos:(int64_t)toPos image:(id)image;

/**
 @brief 获取缩略图失败回调
 @param positionMs 指定的缩略图位置
 */
/****
 @brief Thumbnail image retrieval failure callback.
 @param positionMs The specified thumbnail image position.
 */
- (void)onGetThumbnailFailed:(int64_t)positionMs;

/**
 @brief 播放器状态改变回调
 @param player 播放器player指针
 @param oldStatus 老的播放器状态 参考AVPStatus
 @param newStatus 新的播放器状态 参考AVPStatus
 @see AVPStatus
 */
/****
 @brief Player status update callback.
 @param player Player pointer.
 @param oldStatus The previous status. See AVPStatus.
 @param newStatus The updated status. See AVPStatus.
 @see AVPStatus
 */
- (void)onPlayerStatusChanged:(AliPlayer*)player oldStatus:(AVPStatus)oldStatus newStatus:(AVPStatus)newStatus;

/**
 @brief 获取截图回调
 @param player 播放器player指针
 @param image 图像
 @see AVPImage
 */
/****
 @brief Snapshot retrieval callback.
 @param player Player pointer.
 @param image Snapshot.
 @see AVPImage
 */
- (void)onCaptureScreen:(AliPlayer*)player image:(AVPImage*)image;

/**
 @brief SEI回调
 @param player 播放器player指针
 @param type 类型
 @param data 数据
 @see AVPImage
 */
/****
 @brief SEI callback.
 @param player Player pointer.
 @param type Type.
 @param data Data.
 @see AVPImage
 */
- (void)onSEIData:(AliPlayer*)player type:(int)type data:(NSData *)data;

/**
 @brief 播放器渲染信息回调
 @param player 播放器player指针
 @param timeMs 渲染时的系统时间
 @param pts  视频帧pts
 */
/****
 @brief Player render info callback.
 @param player Player pointer.
 @param timeMs system time when render.
 @param pts  video frame pts
 @see AVPEventType
 */
-(void)onVideoRendered:(AliPlayer*)player timeMs:(int64_t)timeMs pts:(int64_t)pts;

@end

/**
 @brief 埋点事件参数回调
 */
/****
 @brief Event report params
*/
@protocol AVPEventReportParamsDelegate <NSObject>
/**
 @brief 回调
 @param params  埋点事件参数
 */
/****
 @brief call back
 @param params  event params
*/
-(void)onEventReportParams:(NSDictionary<NSString *, NSString *>*)params;
@end
#endif /* AVPDelegate_h */
