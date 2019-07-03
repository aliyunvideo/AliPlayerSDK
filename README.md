# AliPlayer_iOS

# 功能使用

阿里云SDK提供了以下几大功能：

- 单个视频播放功能
- 视频列表播放功能
- 下载视频功能
- 缓存功能

功能具体介绍如下。

<a name="a10bc835"></a>
## 一. 播放功能

播放功能的基本流程如下：

创建播放器->设置事件监听->创建播放源->准备播放器->准备成功后开始播放->播放控制->释放播放器。

<a name="3f171af3"></a>
### 1.创建播放器

可以创建两种播放器：AliPlayer和AliListPlayer。<br />AliListPlayer比AliPlayer多了列表播放的功能，其余功能是一致的。使用方法如下:

```objectivec
self.player = [[AliPlayer alloc] init];
self.listPlayer = [[AliListPlayer alloc] init];
```

如果播放的视频是安全下载后的本地文件（即经过阿里云`加密转码`过后的），那么还需要设置一个加密校验信息（建议在Application中配置一次即可）：

```objectivec
NSString *encrptyFilePath = [[NSBundle mainBundle] pathForResource:@"encryptedApp" ofType:@"dat"];
[AliPrivateService initKey:encrptyFilePath];
```

如果没有设置正确的校验文件，播放安全下载后的文件会报错：ERROR_DEMUXER_OPENSTREAM。

<a name="e787e787"></a>
### 2.设置播放器Delegate

播放器提供了Delegate回调，比如：onPlayerEvent，onError等事件。使用方法如下：

```
@interface SimplePlayerViewController ()<AVPDelegate>
@end

- (void)viewDidLoad {
self.player = [[AliPlayer alloc] init];
self.player.playerView = self.avpPlayerView.playerView;
self.player.delegate = self;
//...
}

/**
@brief 错误代理回调
@param player 播放器player指针
@param errorModel 播放器错误描述，参考AliVcPlayerErrorModel
*/
- (void)onError:(AliPlayer*)player errorModel:(AVPErrorModel *)errorModel {
//提示错误，及stop播放
}

/**
@brief 播放器事件回调
@param player 播放器player指针
@param eventType 播放器事件类型，@see AVPEventType
*/
-(void)onPlayerEvent:(AliPlayer*)player eventType:(AVPEventType)eventType {
switch (eventType) {
case AVPEventPrepareDone: {
// 准备完成
}
break;
case AVPEventAutoPlayStart:
// 自动播放开始事件
break;
case AVPEventFirstRenderedStart:
// 首帧显示
break;
case AVPEventCompletion:
// 播放完成
break;
case AVPEventLoadingStart:
// 缓冲开始
break;
case AVPEventLoadingEnd:
// 缓冲完成
break;
case AVPEventSeekEnd:
// 跳转完成
break;
case AVPEventLoopingStart:
// 循环播放开始
break;
default:
break;
}
}

/**
@brief 视频当前播放位置回调
@param player 播放器player指针
@param position 视频当前播放位置
*/
- (void)onCurrentPositionUpdate:(AliPlayer*)player position:(int64_t)position {
// 更新进度条
}

/**
@brief 视频缓存位置回调
@param player 播放器player指针
@param position 视频当前缓存位置
*/
- (void)onBufferedPositionUpdate:(AliPlayer*)player position:(int64_t)position {
// 更新缓冲进度
}

/**
@brief 获取track信息回调
@param player 播放器player指针
@param info track流信息数组 参考AVPTrackInfo
*/
- (void)onTrackReady:(AliPlayer*)player info:(NSArray<AVPTrackInfo*>*)info {
// 获取多码率信息
}

/**
@brief 字幕显示回调
@param player 播放器player指针
@param index 字幕显示的索引号
@param subtitle 字幕显示的字符串
*/
- (void)onSubtitleShow:(AliPlayer*)player index:(int)index subtitle:(NSString *)subtitle {
// 获取字幕进行显示
}

/**
@brief 字幕隐藏回调
@param player 播放器player指针
@param index 字幕显示的索引号
*/
- (void)onSubtitleHide:(AliPlayer*)player index:(int)index {
// 隐藏字幕
}

/**
@brief 获取截图回调
@param player 播放器player指针
@param image 图像
*/
- (void)onCaptureScreen:(AliPlayer *)player image:(UIImage *)image {
// 预览，保存截图
}

/**
@brief track切换完成回调
@param player 播放器player指针
@param info 切换后的信息 参考AVPTrackInfo
*/
- (void)onTrackChanged:(AliPlayer*)player info:(AVPTrackInfo*)info {
// 切换码率结果通知
}

//...
```

> 具体回调参数的详细说明，参看接口文档。


<a name="8930810a"></a>
### 3. 创建DataSource，准备播放

播放器支持4种播放源：AVPVidStsSource，AVPVidAuthSource，AVPVidMpsSource，AVPUrlSource。其中AVPUrlSource是直接的url播放，其余的三种是通过vid进行播放：AVPVidStsSource推荐点播用户使用；AVPVidAuthSource不建议使用；AVPVidMpsSource仅限MPS用户使用。

以VidSts举例，使用方式如下：

```objectivec
//创建VidSts
AVPVidStsSource *source = [[AVPVidStsSource alloc] init];
source.region = self.接入区域;
source.vid = self.视频vid;
source.securityToken = self.安全token;
source.accessKeySecret = self.临时akSecret;
source.accessKeyId = self.临时akId;
//设置播放源
[self.player setStsSource:source];
//准备播放
[self.player prepare];

```

> MPS视频播放的流程与概念，[参考这里](https://help.aliyun.com/document_detail/53522.html)
> 通过播放凭证VidAuth播放的流程，[参考这里](https://help.aliyun.com/document_detail/57294.html)
> 接入区域Region的设置，参考 [点播中心和访问域名](https://help.aliyun.com/document_detail/98194.html)


<a name="9f5db615"></a>
### 4. 设置显示的view

如果源有画面，那么需要设置显示的view到播放器中，用来显示画面。

```objectivec
self.player.playerView = self.avpPlayerView.playerView;//用户显示的view
```

<a name="622f036c"></a>
### 5. 播放控制

用户自行创建播放器的播放控制按钮，在按钮事件里面实现播放器控制接口。基本控制功能有播放、停止、暂停、拖动（seek），其中Seek功能仅对点播有效，直播使用暂停功能时会使画面停留在当前画面，使用恢复后会开始播放当前画面。使用示例如下：

```objectivec
// 开始播放。
[self.player start];
//暂停播放
[self.player pause];
//停止播放
[self.player stop];
// 跳转到。目前只支持不精准。
[self.player seekToTime:position seekMode:AVP_SEEKMODE_INACCURATE];
// 重置
[self.player reset];
//释放。释放后播放器将不可再被使用。
[self.player destroy];
self.player = nil;
```

<a name="86ac2811"></a>
### 6. 切换多码率

播放器SDK支持HLS多码率地址播放。在`prepare`成功之后，通过`getMediaInfo`可以获取到各个码流的信息，即`TrackInfo`。

```objectivec
AVPMediaInfo *info = [self.player getMediaInfo];
NSArray<AVPTrackInfo*>* tracks = info.tracks;
```

在播放过程中，可以通过调用播放器的`selectTrack`方法切换播放的码流。

```objectivec
[self.player selectTrack:track.trackIndex];
```

切换的结果会在`onTrackChanged`回调：

```objectivec
- (void)onTrackChanged:(AliPlayer*)player info:(AVPTrackInfo*)info {
if (info.trackType == AVPTRACK_TYPE_VIDEO) {
// video changed
}
// etc
}
```
<a name="8b93d7d5"></a>
### 7.自动播放

播放器SDK支持自动播放视频的设置。在`prepare`之前设置autoPlay。

```objectivec
self.player.autoPlay = YES;
```

设置自动播放之后，prepare成功之后，将会自动播放视频。但是注意：自动播放的时候将不会回调`AVPEventPrepareDone`回调，而会回调AVPEventAutoPlayStart回调。

```objectivec
-(void)onPlayerEvent:(AliPlayer*)player eventType:(AVPEventType)eventType {
switch (eventType) {
case AVPEventPrepareDone: {
break;
case AVPEventAutoPlayStart:
break;
}
}
```

<a name="483cbf34"></a>
### 8.循环播放

播放器SDK提供了循环播放视频的功能。设置`loop`开启循环播放, 播放完成后，将会自动从头开始播放视频。

```objectivec
self.player.loop = YES;
```

同时循环开始的回调将会使用`AVPEventLoopingStart`中通知。

<a name="597b947d"></a>
### 9.画面旋转、填充、镜像操作

播放器SDK提供过了多种设置，可以对画面进行精确的控制。包括设置画面旋转模式，设置画面缩放模式，设置镜像模式。

```objectivec
//设置画面的镜像模式：水平镜像，垂直镜像，无镜像。
self.player.mirrorMode = AVP_MIRRORMODE_NONE;
//设置画面旋转模式：旋转0度，90度，180度，270度
self.player.rotateMode = AVP_ROTATE_0;
//设置画面缩放模式：宽高比填充，宽高比适应，拉伸填充
self.player.scalingMode = AVP_SCALINGMODE_SCALEASPECTFIT;
```

画面的旋转模式包括：

| 值 | 说明 |
| --- | --- |
| AVP_ROTATE_0 | 顺时针旋转0度 |
| AVP_ROTATE_90 | 顺时针旋转90度 |
| AVP_ROTATE_180 | 顺时针旋转180度 |
| AVP_ROTATE_270 | 顺时针旋转270度 |


画面的缩放模式包括：

| 值 | 说明 |
| --- | --- |
| AVP_SCALINGMODE_SCALEASPECTFIT | 宽高比适应（将按照视频宽高比等比缩小到view内部，不会有画面变形） |
| AVP_SCALINGMODE_SCALEASPECTFILL | 宽高比填充（将按照视频宽高比等比放大，充满view，不会有画面变形） |
| AVP_SCALINGMODE_SCALETOFILL | 拉伸填充（如果视频宽高比例与view比例不一致，会导致画面变形） |


镜像模式包括：

| 值 | 说明 |
| --- | --- |
| AVP_MIRRORMODE_NONE | 无镜像 |
| AVP_MIRRORMODE_HORIZONTAL | 水平镜像 |
| AVP_MIRRORMODE_VERTICAL | 垂直镜像 |


<a name="9ea6a539"></a>
### 10.静音、音量控制

播放器SDK 提供了对视频的音量控制功能。设置muted播放器静音，设置`volume`控制音量大小,范围是0~1。

```objectivec
//设置播放器静音
self.player.muted = YES;
//设置播放器音量,范围0~1.
self.player.volume = 1.0f;
```

[]()
<a name="e8c85870"></a>
### 11.倍数播放

播放器SDK 提供了倍数播放视频的功能，通过设置`rate`方法, 能够以0.5倍~2倍数去播放视频。同时保持变声不变调。

```objectivec
//设置倍速播放:支持0.5~2倍速的播放
self.player.rate = 1.0f;
```

[]()
<a name="226b94ee"></a>
### 12.截图功能

播放器SDK提供了对当前视频截图的功能`snapshot`。截取的是原始的数据，并转为bitmap返回。回调接口为`onCaptureScreen`。 注意：截图是不包含界面的。

```objectivec
//截图回调
- (void)onCaptureScreen:(AliPlayer *)player image:(UIImage *)image {
// 处理截图
}

//截取当前播放的画面
aliyunVodPlayer.snapshot();
```

[]()
<a name="36e02a31"></a>
### 13. 边播边缓存

播放器SDK提供了边播边缓存的功能，能够让用户重复播放视频时，达到省流量的目的。只需在`prepare`之前给播放器配置`AVPCacheConfig`即可实现此功能。

> 如果播放了加密视频，还需要一个加密校验文件的配置。参看【14. 配置加密校验文件】


```objectivec
AVPCacheConfig *config = [[AVPCacheConfig alloc] init];
//开启缓存功能
config.enable = YES;
//能够缓存的单个文件最大时长。超过此长度则不缓存
config.maxDuration = 100;
//缓存目录的位置，需替换成app期望的路径
config.path = @"please use your cache path here";
//缓存目录的最大大小。超过此大小，将会删除最旧的缓存文件
config.maxSizeMB = 200;
//设置缓存配置给到播放器
[self.player setCacheConfig:config];
```

缓存成功之后，以下情况将会利用缓存文件（必须已经设置了`setCacheConfig`）

1. 如果设置了循环播放，那么第二次播放的时候，将会自动播放缓存的文件。
1. 缓存成功后，重新创建播放器，播放同样的资源，也会自动使用缓存文件。

> 注意：vid的缓存文件是通过vid等信息定位的，所以，对于VID的缓存文件，将需要网络请求信息之后才能确定使用哪个缓存文件。


同时，播放器提供了获取缓存文件路径的接口：

```objectivec
-(NSString *) getCacheFilePath:(NSString *)URL;
功能：根据url获取缓存的文件名。必须先调用setCacheConfig才能获取到。
参数：URL URL
返回值：最终缓存的文件绝对路径。

-(NSString *) getCacheFilePath:(NSString *)vid format:(NSString *)format definition:(NSString *)definition;
功能：根据vid 获取缓存的文件名。必须先调用setCacheConfig才能获取到。
参数：vid        视频id。format     视频格式。definition 视频清晰度。previewTime 试看时长。
返回值：最终缓存的文件绝对路径。
```

边播边缓存也不是所有的视频都会缓存，**有些情况是不会缓存的**。这里详细介绍一下：<br />1.对于直接播放URL的方式，即`AVPUrlSource`。如果是HLS(即m3u8)地址，将**不会**缓存。如果是其他支持的格式，则根据缓存配置进行缓存。<br />2.对于VID的方式播放，将会根据缓存配置进行缓存。<br />3.播放器读取完全部的数据则视为缓存成功。如果在此之前，调用`stop`，或者出错`onError`，则缓存将会失败。<br />4.cache内的seek的操作不会影响缓存结果。cache外的seek会导致缓存失败。<br />5.如果加密文件与app信息不一致，将会缓存失败。<br />6.cache的结果回调，会通过`onPlayerEventInfo`回调。

```objectivec
-(void)onPlayerEvent:(AliPlayer*)player eventWithString:(AVPEventWithString)eventWithString description:(NSString *)description {
if (eventWithString == EVENT_PLAYER_CACHE_SUCCESS) {
//缓存成功事件。
}else if (eventWithString == EVENT_PLAYER_CACHE_ERROR) {
//缓存失败事件。
}
}
```

[]()
<a name="55a005f6"></a>
### 14. 试看功能

试看功能是指：当设置试看的时长，通过播放器SDK播放视频时，服务端将不会返回完整的视频内容，而是返回试看时间段的内容。<br />播放器SDK 通过配合点播服务配置，可以实现试看功能，支持VidSts和VidAuth两种方式。如何配置和使用试看功能参考 [点播试看最佳实践](https://help.aliyun.com/document_detail/120987.html) 。配置试看功能之后，通过SDK 的VidPlayerConfigGen的`setPreviewTime`方法设置播放器的试看时长。以AVPVidStsSource为例：

```objectivec
AVPVidStsSource *source = [[AVPVidStsSource alloc] init];
....
VidPlayerConfigGenerator* vp = [[VidPlayerConfigGenerator alloc] init];
[vp setPreviewTime:20];//20秒试看
source.playConfig = [vp generatePlayerConfig];//设置给播放源
...
```

`VidPlayerConfigGen`支持设置服务端支持的请求参数。点击查看 [请求参数说明](https://help.aliyun.com/document_detail/86952.html#PlayConfig)。

[]()
<a name="f6870780"></a>
### 15. 硬解开关

播放器SDK 提供了264，265的硬解码能力，同时提供了`enableHardwareDecoder`提供开关。默认开，并且在硬解初始化失败时，自动切换为软解，保证视频的正常播放。

```objectivec
//开启硬解。默认开启
self.player.enableHardwareDecoder = YES;
```

如果从硬解自动切换为软解，将会通过`onPlayerEvent`回调：

```objectivec
-(void)onPlayerEvent:(AliPlayer*)player eventWithString:(AVPEventWithString)eventWithString description:(NSString *)description {
if (eventWithString == EVENT_SWITCH_TO_SOFTWARE_DECODER) {
//切换到软解
}
}
```

[]()
<a name="2c7a7d86"></a>
### 16. 设置Referer

播放器SDK提供了`AVPConfig` 用来设置请求referer。配合控制台的黑白名单referer，可以控制访问权限。播放器SDK的设置如下：

```objectivec
//先获取配置
AVPConfig *config = [self.player getConfig];
//设置referer
config.referer = referer;
....//其他设置
//设置配置给播放器
[self.player setConfig:config];
```


<a name="IXXHR"></a>
### 17. 设置UserAgent

播放器SDK提供了`AVPConfig` 用来设置请求UA。设置之后，播放器请求的过程中将会带上UA信息。播放器SDK的设置如下：

```objectivec
//先获取配置
AVPConfig *config = [self.player getConfig];
//设置userAgent
config.userAgent = userAgent;
....//其他设置
//设置配置给播放器
[self.player setConfig:config];
```


<a name="jVO0a"></a>
### 18. 配置网络重试时间和次数

通过`AVPConfig`，用户可以设置播放器SDK的网络超时的时间和重试次数。播放器SDK的设置如下：

```objectivec
//先获取配置
AVPConfig *config = [self.player getConfig];
//设置网络超时时间，单位ms
config.networkTimeout = 5000;
//设置超时重试次数。每次重试间隔为networkTimeout。networkRetryCount=0则表示不重试，重试策略app决定，默认值为2
config.networkRetryCount = 2;
....//其他设置
//设置配置给播放器
[self.player setConfig:config];
```

1. 如果设置了networkRetryCount：如此时发生网络问题，导致出现loading后，那么将会重试networkRetryCount次，每次的间隔时间为networkTimeout。 如果重试多次之后，还是loading的状态，那么就会回调`onError`事件，此时，AVPErrorModel.code为ERROR_LOADING_TIMEOUT。
1. 如果networkRetryCount设置为0，当网络重试超时的时候，播放器就会回调onPlayerEvent，参数eventWithString为EVENT_PLAYER_NETWORK_RETRY。 此时，可以调用播放器的`reload`方法进行重新加载网络，或者进行其他的处理。

[]()
<a name="3519f35d"></a>
### 19. 配置缓存和延迟控制

对于播放器来说，缓存的控制非常重要。合理的配置，可以有效的加快起播速度，减少卡顿。播放器SDK通过`AVPConfig`提供了设置缓存和延迟的控制接口。

```objectivec
//先获取配置
AVPConfig *config = [self.player getConfig];
//最大延迟。注意：直播有效。当延时比较大时，播放器sdk内部会追帧等，保证播放器的延时在这个范围内。
config.maxDelayTime = 5000;
// 最大缓冲区时长。单位ms。播放器每次最多加载这么长时间的缓冲数据。
config.maxBufferDuration = 50000;
//高缓冲时长。单位ms。当网络不好导致加载数据时，如果加载的缓冲时长到达这个值，结束加载状态。
config.highBufferDuration = 3000;
// 起播缓冲区时长。单位ms。这个时间设置越短，起播越快。也可能会导致播放之后很快就会进入加载状态。
config.startBufferDuration = 500;
//其他设置
//设置配置给播放器
[self.player setConfig:config];
```

> 注意：三个缓冲区时长的大小关系必须为：startBufferDuration<=highBufferDuration<=maxBufferDuration。


<a name="b2YMX"></a>
### 20. 支持HTTP Header设置

播放器通过AVPConfig参数，可以给播放器中的请求加上http的header参数。代码如下：

```objectivec
//先获取配置
AVPConfig *config = [self.player getConfig];
//定义header
NSMutableArray *httpHeaders = [[NSMutableArray alloc] init];
//比如使用httpdns时，需要设置Host。
[httpHeaders addObject:@"Host:xxx.com"];
//设置header
config.httpHeaders = httpHeaders;
....//其他设置
//设置配置给播放器
[self.player setConfig:config];
```


<a name="SQar9"></a>
## 二. 列表播放功能

当前短视频列表播放比较流行。阿里播放器提供了完整的列表播放功能，内部包含预加载机制，大幅提高了视频的起播速度。列表播放的基本流程如下：

创建播放器->设置事件监听->添加多个播放源->播放某个播放源->播放控制->移动播放某个源->释放播放器。

> 播放的功能与接口与上节播放功能一致。多了一些列表控制功能。播放器的创建，监听，控制，释放等功能，参考上一节内容


<a name="3f171af3-1"></a>
### 1.创建播放器

`AliListPlayer`比`AliPlayer`多了列表播放的功能，其余功能是一致的。列表播放就使用`AliListPlayer`。创建方法如下:

```objectivec
self.listPlayer = [[AliListPlayer alloc] init];
```

<a name="e74d2e39"></a>
### 2. 设置预加载个数

合理设置预加载个数，能够有效的提高起播的速度。

```objectivec
//设置预加载个数。总共加载的个数为： 1 + count*2。
self.listplyer.preloadCount = 2;
```

<a name="ce1362c4"></a>
### 3. 添加/移除 多个播放源

列表播放支持两种播放源：AVPVidStsSource和AVPUrlSource。url为直接的url地址，vid为点播视频id。

> 不支持VidAuth和VidMps的方式。


```objectivec
//添加vid源
[self.listPlayer addVidSource:videoId uid:UUIDString];
//添加URL源
[self.listPlayer addUrlSource:URL uid:UUIDString];
//移除某个源
[self.listPlayer removeSource:UUIDString];
```

> uid是视频的唯一标志。用于区分视频是否一样。如果uid一样，则认为是一样的。
> 如果播放出现串流的情况，请注意查看是不是在不同的界面设置了同一个uid。


<a name="2c2293ff"></a>
### 4. 播放某个源

添加了一个或多个播放源之后，便可以播放某个源。接口如下：

```objectivec
//url时使用此接口
- (BOOL) moveTo:(NSString*)uid;
//vid的时候使用此接口，需要传递stsInfo，保证不会失效
- (BOOL) moveTo:(NSString*)uid accId:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;
```

<a name="f97ddc87"></a>
### 4. 播放上一个、下一个视频

播放器提供了moveToPrev，moveToNext接口用于播放上一个，下一个视频

```
//移动到下一个视频。 注意：只能用于url的源。这个方法不适用于vid的播放。
- (BOOL) moveToNext;
//移动到上一个视频。注意：只能用于url的源。这个方法不适用于vid的播放。
- (BOOL) moveToPre;
//移动到下一个视频。注意：只能用于vid的播放。
- (BOOL) moveToNext:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;
// 移动到上一个视频。注意：只能用于vid的播放。
- (BOOL) moveToPre:(NSString*)accId accKey:(NSString*)accKey token:(NSString*)token region:(NSString*)region;
```


<a name="de0f4da1"></a>
## 三. 视频下载功能

阿里云SDK提供了点播服务视频的下载功能，能够通过VidSts和VidAuth下载点播服务上的视频。同时，下载的方式提供了`安全下载`和`普通下载`的模式（在控制台设置）。<br />`普通下载`含义是：即使点播服务已经加密过了，下载后的视频数据也不是经过阿里云加密的。也就是说，**用户可以用第三方播放器播放。**<br />`安全下载`含义是：即使点播服务没有加密视频，下载后的视频数据也是经过阿里云加密的。也就是说，**用户用第三方播放器是播放不了的。只能使用阿里云的播放器去播放**

视频下载的基本流程如下：

创建并设置下载器->设置事件监听->准备下载源->准备成功后选择下载项->更新下载源并开始下载->下载成功/失败后，释放下载器。

[]()
<a name="efc5bb5c"></a>
### 1. 创建并设置下载器

创建下载器。代码如下：

```objectivec
AliMediaDownloader *downloader = [[AliMediaDownloader alloc] init];
[downloader setSaveDirectory:self.downLoadPath];
[downloader setDelegate:self];
```

下载SDK支持私有加密的下载。为了保证安全性，需要配置一个加密校验文件到播放器。（建议在Application中配置一次即可）

```objectivec
NSString *encrptyFilePath = [[NSBundle mainBundle] pathForResource:@"encryptedApp" ofType:@"dat"];
[AliPrivateService initKey:encrptyFilePath];
```

下载时如果是安全下载，那么不一致的话，会导致下载失败。

[]()
<a name="d58c5976"></a>
### 2. 设置监听事件

下载器提供了多个事件监听。设置代码如下：

```objectivec
-(void)onPrepared:(AliMediaDownloader *)downloader mediaInfo:(AVPMediaInfo *)info {
//准备下载项成功
}

-(void)onError:(AliMediaDownloader *)downloader errorModel:(AVPErrorModel *)errorModel {
//下载出错
}

-(void)onDownloadingProgress:(AliMediaDownloader *)downloader percentage:(int)percent {
//下载进度百分比
}

-(void)onProcessingProgress:(AliMediaDownloader *)downloader percentage:(int)percent {
//处理进度百分比
}

-(void)onCompletion:(AliMediaDownloader *)downloader {
//下载成功
}

```

[]()
<a name="71f9c69f"></a>
### 3.准备下载源

通过`preapre`方法准备下载源。下载源支持AVPVidStsSource和AVPVidAuthSource两种。以AVPVidStsSource举例：

```objectivec
//创建VidSts
AVPVidStsSource* stsSource = [[AVPVidStsSource alloc] init];
stsSource.vid = source.vid;//视频vid
stsSource.region = DEFAULT_SERVER.region;//接入区域
stsSource.securityToken = DEFAULT_SERVER.securityToken;//安全token
stsSource.accessKeySecret = DEFAULT_SERVER.accessKeySecret;//临时akSecret
stsSource.accessKeyId = DEFAULT_SERVER.accessKeyId;//临时akId
//准备下载源
[downloader prepareWithVid:stsSource];
```

[]()
<a name="3dba3bf9"></a>
### 4.准备成功后选择下载项

准备成功后，会回调`onPrepared`方法。选择某个Track进行下载：

```objectivec
-(void)onPrepared:(AliMediaDownloader *)downloader mediaInfo:(AVPMediaInfo *)info {
NSArray<AVPTrackInfo*>* tracks = info.tracks;
//比如：下载第一个TrackInfo
[downloader selectTrack:[tracks objectAtIndex:0].trackIndex];
}
```

[]()
<a name="fa0504cc"></a>
### 5.更新下载源并开始下载

经过第4步之后，就可以开始下载了(为了防止VidSts和VidAuth过期，最好更新一下下载源的信息)：

```objectivec
//更新下载源
[downloader updateWithVid:vidSource]
//开始下载
[downloader start];
```

[]()
<a name="9cba2e86"></a>
### 6.下载成功/失败后，释放下载器

下载成功后，调用`destroy`释放下载器。

```objectivec
[self.downloader destroy];
self.downloader = nil;
```














