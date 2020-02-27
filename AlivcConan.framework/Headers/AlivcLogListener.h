#ifndef Alivc_Log_Listener_h
#define Alivc_Log_Listener_h

namespace AlivcConan
{
  class AlivcLog;

  class AlivcLogListener
  {
  public:
    /**
    *@brief 创建日志文件成功
    */
    CONAN_EXTERN
    virtual void OnCreateLogFileSuccess(AlivcLog* logInstance, const char* logFilePath) = 0;

    /**
    *@brief 上报日志文件成功
    */
    CONAN_EXTERN
    virtual void OnUploadFileSuccess(AlivcLog* logInstance, const char* logFilePath, const char* uploadPath) = 0;


    /**
    *@brief 上报日志文件结束
    */
    CONAN_EXTERN
    virtual void OnUploadFilesFinish() = 0;


      /**
      *@brief 初始化完成(初始化完成后才可上传日志)
      */
    CONAN_EXTERN
    virtual void OnInitComplete(AlivcLog* logInstance) = 0;

    /**
    *@brief 日志实例错误发生
    *@param[in]  report 日志实例
    *@param[in]  errorCode 错误码
    *@remark
    */
    CONAN_EXTERN
    virtual void OnLogErrorOccur(AlivcLog* logInstance, int errorCode) = 0;

    /**
    *@brief 鉴权信息即将失效
    *@remark 配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息
    */
    CONAN_EXTERN
    virtual void OnStsWillExpireSoon(AlivcLog* logInstance, unsigned long afterTime) = 0;

    /**
    *@brief 鉴权信息失效
    *@remark 配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息
    */
    CONAN_EXTERN
    virtual void OnStsExpired(AlivcLog* logInstance) = 0;
  };
}
#endif //Alivc_Log_Listener_h