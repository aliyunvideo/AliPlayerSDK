#ifndef Alivc_Log_h
#define Alivc_Log_h

#include "AlivcConanExport.h"
#include "AlivcConanDefine.h"
#include "AlivcLogConfig.h"
#include "AlivcLogListener.h"

namespace AlivcConan
{
  /*
  @brief 日志上报接口类
  */
  class AlivcLog
  {
  public:
    /**
    *@brief 创建日志实例
    */
    CONAN_EXTERN
    static AlivcLog* CreateLogInstance(AlivcLogConfig config);

    /**
    *@brief 通过id查找获取日志实例
    */
    CONAN_EXTERN
    static AlivcLog* GetLogInstanceById(long long id);

    /**
    *@brief 释放日志实例
    *@param[in] logInstanc 日志实例
    *@remark 调用释放后不可在操作此日志操作实例
    */
    CONAN_EXTERN
    static void Release(AlivcLog* logInstance);

    /**
    *@brief 初始化日志上报信息（鉴权信息）
    *@remark
    */
    CONAN_EXTERN
    virtual void Init() = 0;

    /**
    *@brief 设置当前网络状态
    *@param[in]  type 网络状态
    *@remark
    */
    CONAN_EXTERN
    virtual void SetNetworkType(NetworkType type) = 0;

    /**
    *@brief 设置日志上报策略
    *@param[in]  strategy 上报策略
    *@remark
    */
    CONAN_EXTERN
    virtual void SetUploadLogStrategy(UploadLogStrategy strategy) = 0;

    /**
    *@brief 设置日志实例回调
    *@param[in]  listener 日志实例事件监听器
    *@remark
    */
    CONAN_EXTERN
    virtual void SetLogListener(AlivcLogListener* listener) = 0;

    /**
    *@brief 设置Trace Id
    *@param[in]  traceId
    */
    CONAN_EXTERN
    virtual void SetTraceId(const char* traceId) = 0;

    /**
    *@brief 设置Session Id
    *@param[in]  sessionId
    */
    CONAN_EXTERN
    virtual void SetSessionId(const char* sessionId) = 0;

    /**
      *@brief 设置应用id
      *@param[in] appId
      */
    CONAN_EXTERN
    virtual void SetAppId(const char* appId) = 0;

    /**
      *@brief 设置子模块名称
      *@param[in] module
      */
    CONAN_EXTERN
    virtual void SetSubModule(const char* module) = 0;

    /**
     *@brief 设置系统版本
     *@param[in] version
     */
    CONAN_EXTERN
    virtual void SetOSVersion(const char* version) = 0;

    /**
     *@brief 设置sdk版本
     *@param[in] version
     */
    CONAN_EXTERN
    virtual void SetSDKVersion(const char* version) = 0;

    /**
    *@brief 获取日志实例Id
    *@return 日志实例Id
    *@remark
    */
    CONAN_EXTERN
    virtual long long GetId() = 0;

    /**
    *@brief 设置日志模式
    *@param[in] mode 日志模式
    */
    CONAN_EXTERN
    virtual void SetLogModel(int mode) = 0;

    /**
    *@brief 设置日志等级
    *@param[in]  level 日志等级
    */
    CONAN_EXTERN
    virtual void SetLogLevel(AlivcLogLevel level) = 0;

    /**
    *@brief 关闭日志
    */
    CONAN_EXTERN
    virtual void DisableLog() = 0;

    /**
    *@brief 设置日志文件保存路径
    *@param[in]  logFilePath 日志文件保存路径
    *@return  成功返回0， 失败返回-1
    *@remark 当日志模式包含LogModeFile时，需要在首次打印日志前设置缓存路径，后续日志文件将保存在缓存路径
    *@remark 若未设置缓存路径，默认在程序当前路径下输出日志文件
    */
    CONAN_EXTERN
    virtual void SetLogFileCachePath(const char* path) = 0;

    /**
    *@brief 添加信息日志
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int I(const char* msg) = 0;

    /**
    *@brief 添加信息日志
    *@param[in]  tag 日志标签
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int I(const char* tag, const char* msg) = 0;

    /**
    *@brief 添加警告日志
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int W(const char* msg) = 0;

    /**
    *@brief 添加警告日志
    *@param[in]  tag 日志标签
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int W(const char* tag, const char* msg) = 0;

    /**
    *@brief 添加错误日志
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int E(const char* msg) = 0;

    /**
    *@brief 添加错误日志
    *@param[in]  tag 日志标签
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int E(const char* tag, const char* msg) = 0;

    /**
    *@brief 添加调试日志
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int D(const char* msg) = 0;

    /**
    *@brief 添加调试日志
    *@param[in]  tag 日志标签
    *@param[in]  msg 日志消息
    *@remark
    */
    CONAN_EXTERN
    virtual int D(const char* tag, const char* msg) = 0;

    /**
    *@brief 上报日志文件到OSS服务
    *@param[in]  logFileDir 日志文件文件夹路径(默认为日志文件缓存路径）
    *@param[in]  filePrefix 日志文件前缀(默认不校验前缀)
    *@param[in]  fileSuffix 日志文件前缀(默认文件后缀为.txt)
    *@remark 需要通过SetAccessInfo和SetBucket方法设置上报OSS的相关信息
    */
    CONAN_EXTERN
    virtual int UploadLogFile(const char* logFileDir = NULL, const char* filePrefix = NULL, const char* fileSuffix = NULL) = 0;

    /**
    *@brief 存储Crash信息到日志文件
    *@param[in]  filePath 存储文件路径
    *@param[in]  content crash捕获信息
    *@remark
    */
    CONAN_EXTERN
    virtual int SaveCrashInfoToLogFile(const char* filePath, const char* content) = 0;

    /**
    *@brief 设置上传日志文件后是否移除本地文件
    *@param[in]  enable  设置为true时，上传日志完毕移除本地文件，设置为false时不移除
    *@remark
    */
    CONAN_EXTERN
    virtual void RemoveLogFileAfterUpload(bool enable) = 0;

    /**
    *@brief 设置上传日志文件后是否要释放日志上报组件
    *@param[in]  autoRelease  设置为true时，上传日志完毕释放资源，设置为false时不释放
    *@remark
    */
    CONAN_EXTERN
    virtual void SetAutoReleaseAfterUpload(bool autoRelease) = 0;

    /**
    *@brief 设置上传日志文件的最大字节数
    *@param[out]
    *@param[in]  maxFileSizeBytes  上传日志文件上限字节数
    *@return     void
    *@remark 日志文件大小低于设置值时才会上传，未设置时不限制大小
    */
    CONAN_EXTERN
    virtual void SetMaxFileSize(long maxFileSizeBytes) = 0;

    /**
    *@brief 重新设置OSS鉴权信息
    *@param[out]
    *@param[in]  const char * accessKey  OSS服务accessId
    *@param[in]  const char * secretKey  OSS服务accessKey
    *@param[in]  const char * securityToken  OSS动态Token鉴权
    *@param[in]  const char * expireTime  STS鉴权信息过期时间
    *@remark 使用外部鉴权时鉴权到期需要重新设置
    */
    CONAN_EXTERN
    virtual int ResetAcessTokenInfo(const char* accessKey, const char* secretKey, const char* securityToken, const char* expireTime) = 0;

  protected:
    AlivcLog() {}
    virtual ~AlivcLog() {}
  };

}

#endif //Alivc_Log_h
