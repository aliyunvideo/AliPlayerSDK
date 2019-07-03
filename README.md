# AliyunPlayer_iOS

## 简介
- [AliyunPlayer_iOS](https://help.aliyun.com/document_detail/61905.html?spm=5176.doc61431.6.684.6Do9wB)播放器是一款在阿里云视频点播产品中使用的、基于iOS平台的多媒体视频播放SDK。依托于强大的阿里云视频平台，您可以使用该SDK快速集成视频播放的能力，开发内容丰富的iOS端移动视频应用。
- 基础播放器(AliyunPlayerSDK)：**提供播放视频的基础能力，仅支持URL的方式播放，建议使用阿里云CDN+OSS存储或使用其他第三方服务的用户使用。
- 高级播放器(AliyunVodPlayerSDK)：**除了具备基础播放器的所有功能外，还提供播放视频的高级能力，如视频加密、安全下载、边播边下缓存、清晰度切换等功能，建议使用阿里视频云点播和直播业务的用户使用。
- UI播放器(AliyunVodPlayerViewSDK)：**阿里云提供的带多套皮肤的播放器，建议对播放器个性化要求比较低并且想最快速度实现播放功能的用户使用。




### 设备和系统版本

- iOS系统版本：iOS 8.0及以上

### 安装包下载及说明
- 播放器SDK及Demo,请点击[下载](https://help.aliyun.com/document_detail/51992.html?spm=5176.doc51787.6.646.BpeBmK)

```
arm文件夹：release版本，用于应用发布。
arm&simulator文件夹：debug和release通用版本，用于模拟器和真机测试。
AliyunLanguageSource.bundle ： 多语言库
AliyunPlayerSDK.framework ： 基础播放器动态库
AliyunVodPlayerSDK.framework ：高级播放器动态库
AliyunImageSource.bundle: UI播放器图片库，如果集成ui播放器必须添加。
AliyunVodPlayerViewSDK.framework : UI播放器动态库
```

## Pod依赖

```
    pod 'AliyunPlayer_iOS'
```

## 简单使用

- [基础播放器(AliyunPlayerSDK)](https://help.aliyun.com/document_detail/61899.html)
```
 AliVcMediaPlayer *mediaPlayer = [[AliVcMediaPlayer alloc] init];
 UIView *view =  [[UIView alloc] initWithFrame:CGRectZero];
 [self.view addSubview:view];
 view.frame = CGRectMake(0, 100, self.view.frame.size.width, self.view.frame.size.width*9/16);
 [mediaPlayer create:view];
 AliVcMovieErrorCode code = [mediaPlayer prepareToPlay:[NSURL URLWithString:@"http://player.alicdn.com/video/aliyunmedia.mp4"]];
 if (code !=ALIVC_SUCCESS) {
        NSLog(@"播放失败");
    }else{
        [mediaPlayer play];
    }
```

- [高级播放器(AliyunVodPlayerSDK)](https://help.aliyun.com/document_detail/61900.html)
```
  @property (nonatomic,strong)AliyunVodPlayer *aliplayer;
  self.aliplayer = [[AliyunVodPlayer alloc] init];
  UIView *view =  [[UIView alloc] initWithFrame:CGRectZero];
  view = self.aliplayer.playerView;
  [self.view addSubview:view];
  view.frame = CGRectMake(0, self.view.frame.size.width*9/16+20, self.view.frame.size.width, self.view.frame.size.width*9/16);
  [self.aliplayer setAutoPlay:YES];
  [self.aliplayer prepareWithURL:[NSURL URLWithString:@"http://player.alicdn.com/video/aliyunmedia.mp4"]];
```

- [UI播放器(AliyunVodPlayerViewSDK)](https://help.aliyun.com/document_detail/61902.html)
```
    CGRect frame = CGRectMake(0, self.view.frame.size.width*9/16+20, self.view.frame.size.width, self.view.frame.size.width*9/16);
    AliyunVodPlayerView *playerView =[[AliyunVodPlayerView alloc] initWithFrame:frame andSkin:AliyunVodPlayerViewSkinRed];
    [playerView setAutoPlay:YES];
    [playerView playViewPrepareWithURL:[NSURL URLWithString:@"http://player.alicdn.com/video/aliyunmedia.mp4"]];
    [self.view addSubview:playerView];
```


- 注意事项
```
1、SDK提供的是动态链接库，请参考SDK导入说明中动态库的方式添加。
2、当前SDK仅支持HLS、RTMP、HTTP FLV、mp4、mp3等流格式，支持的视频编码格式为H264，音频编码格式为AAC。建议使用MTS或点播平台转码后使用。
3、适配iPhone5S以上机型，低端机型在使用变速功能时可能存在性能问题。
4、swift用户可以参考Demo中的`AliyunPlayerMediaDemo-Swift`这个Target。
5、从V3.2.0开始建议使用STS的播放方式，主要原因是STS是阿里云官网统一的授权系统，更为标准。而v3.2.0之前采用的playAuth是点播平台独有的，在安全性和使用性方面两者并无差别，老用户可以继续使用。
6、使用点播上传不转码的用户，在使用vid播放时需要配合V3.1.0之后的版本使用。
```

## 版本更新
### 3.4.5
```
UI播放器已经开源，pod集成中在添加UI播放器的SDK部分，同时包括图片库。
```
### 3.2.0
第一版。
### 3.2.1
更新AliyunLanguageSource.bundle、AliyunImageSource.bundle ，simular->release,解决App Store上架问题。

### 3.3.3
优化更新。


## 常见问题

### 1.build提示编译错误。
```
dyld: Library not loaded: @rpath/AliyunPlayerSDK.framework/AliyunPlayerSDK
  Referenced from: /private/var/containers/Bundle/Application/02753F5B-EFAD-40C3-AD5E-EC77C16E2100/zbzhixue.app/Frameworks/AliyunVodPlayerSDK.framework/AliyunVodPlayerSDK
  Reason: image not found
```

>解决方案：AliyunVodPlayer(高级播放器)是依赖与 AliyunPlayerSDK(基础播放器)支持，所以项目中 targets -> Build Phases -> Link Binary With Libraries 中需要引入AliyunPlayerSDK.framework、AliyunVodPlayer.framework俩个动态库。

### 2.后台下载功能

```
实现app进入后台，继续下载视频功能。
```
>解决方案：</br>1.设置
 UIBackgroundTaskIdentifier taskId;
 
 2.循环启动-休眠
 -(void)applicationDidEnterBackground:(UIApplication *)application {
 //    需要后台下载打开
 taskId = [application beginBackgroundTaskWithExpirationHandler:^{
 [application endBackgroundTask:taskId];
 }];
 
 3.resignActiveDemo 继续下载 ，调用 [[AliyunVodDownLoadManager shareManager] startDownloadMedia:model];
 //下载数据部分。DownloadViewController单例。
 //         [[DownloadViewController sharedViewController] resignActiveDemo];
 }

### 3. Push界面跳转对UI播放器旋转产生的影响
```
假设：UINavigationController下 A、B、C 三个界面，
A界面是空界面
B界面增加对旋转设定。
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation{
return toInterfaceOrientation = UIInterfaceOrientationPortrait;
}
- (BOOL)shouldAutorotate{
return NO;
}
-(UIInterfaceOrientationMask)supportedInterfaceOrientations{
return UIInterfaceOrientationMaskPortrait;
}

C中包含有UI播放器的UIViewController,如图3.0.1、3.0.2

当B push C，会对C界面的横屏旋转产生影响，使UI播放器无法旋转。


```
[3.0.1](http://docs-aliyun.cn-hangzhou.oss.aliyun-inc.com/assets/pic/51802/cn_zh/1511258771647/101.png)
[3.0.2](http://docs-aliyun.cn-hangzhou.oss.aliyun-inc.com/assets/pic/51802/cn_zh/1511258796532/102.png)


>解决方案：创建UINavigationController+autorotate.h 分类，重写旋转方法， 此方案需要根据具体需求来实现。</br>#import "UINavigationController+autorotate.h"

@implementation UINavigationController (autorotate)

-(BOOL)shouldAutorotate {
return [[self.viewControllers lastObject] shouldAutorotate];
}

-(NSUInteger)supportedInterfaceOrientations {
return [[self.viewControllers lastObject] supportedInterfaceOrientations];
}

-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
return [[self.viewControllers lastObject] preferredInterfaceOrientationForPresentation];
}
@end


###  4.播放相册中视频
```
播放iphone手机相册中的视频
```
>解决方案：支持HLS、MP4等主流媒体播放格式， 对于手机相册中视频格式MOV也是支持的，但是对于路径访问受限，所以无法播放。

### 5.CFBundleExecutable 问题
```
ERROR ITMS-90535: "Unexpected CFBundleExecutable Key. The bundle at 'Payload/xxx.app/AliyunLanguageSource.bundle' does not contain a bundle executable. If this bundle intentionally does not contain an executable, consider removing the CFBundleExecutable key from its Info.plist and using a CFBundlePackageType of BNDL. If this bundle is part of a third-party framework, consider contacting the developer of the framework for an update to address this issue."
```
>解决方案：删除AliyunLanguageSource.bundle下，info.plist文件中的CFBundleExecutable键值对。













