#ifndef Alivc_Log_Config_h
#define Alivc_Log_Config_h

#include <string>

namespace AlivcConan
{
  /**
  @brief 日志模式
  */
  enum AlivcLogMode
  {
    AlivcLogModeLocal = 0x0001,  /**< 打印到控制台 */
    AlivcLogModeFile = 0x0002,   /**< 打印到文件 */
  };

  /**
  @brief 日志等级
  */
  enum AlivcLogLevel
  {
    AlivcLogLevelDebug = 0,    /**< 调试 */
    AlivcLogLevelInfo = 1,     /**< 信息 */
    AlivcLogLevelWarn = 2,     /**< 警告 */
    AlivcLogLevelError = 3,    /**< 错误 */
    AlivcLogLevelFatal = 4,    /**< 严重 */
  };

  /**
  @brief 日志上报策略
  */
  enum UploadLogStrategy
  {
    AnyCondition,   //不限条件
    OnlyWiFi,       //只在WiFi下上报
  };

  /*
  @brief 日志上报实例配置类
  */
  class AlivcLogConfig
  {
  public:
      CONAN_EXTERN AlivcLogConfig() {}
      CONAN_EXTERN ~AlivcLogConfig() {}

    const char* mClientID{ nullptr };                            //设备唯一Id（UUID)
    const char* mTerminalType{ nullptr };                        //终端类型,如pc，pad，iphone，andorid
    const char* mDeviceModel{ nullptr };                         //设备型号，如iPhone8
    BusinessType mBussinessType;                                 //业务类型

    bool mUseExternalAuth{ false };                              //是否使用外部鉴权(默认内部根据业务类型获取鉴权信息，如需外部自主获取鉴权，需开启此配置)
    const char* mEndPoint{ nullptr };                            //OSS服务endpoint(使用外部鉴权时必须设置)
    const char* mBucket{ nullptr };                              //OSS服务bucket(使用外部鉴权时必须设置)

    const char* mAccessKey{ nullptr };                            //OSS服务鉴权信息accessKey(使用外部鉴权时必须设置)
    const char* mSecretKey{ nullptr };                            //OSS服务鉴权信息secretKey(使用外部鉴权时必须设置)
    const char* mSecurityToken{ nullptr };                        //OSS服务鉴权信息securityToken(使用外部鉴权时必须设置)
    const char* mExpireTime{ nullptr };                           //OSS服务鉴权信息expireTime(使用外部鉴权时必须设置)
  };
}

#endif //Alivc_Log_Config_h
