#ifndef Alivc_Conan_Define_h
#define Alivc_Conan_Define_h

namespace AlivcConan
{
  /**
  @brief 业务类型
  */
  enum BusinessType
  {
    None = 0,                 //无
    Svideo = 1,               //短视频
    Pusher = 2,               //推流
    Player = 3,               //播放器
    InteractiveLive = 4,      //互动直播
    WhiteBoard = 5,           //白板
  };

  /**
  @brief 网络类型
  */
  enum NetworkType
  {
    NetworkTypeUnknow = 0,
    NetworkTypeWLAN = 1,
    NetworkTypeWiFi = 2,
  };
}
#endif //Alivc_Conan_Define_h
