#ifndef Alivc_Event_Report_Listener_h
#define Alivc_Event_Report_Listener_h

#include <string>
#include <map>

namespace AlivcConan
{
  class AlivcEventReport;

  /*
  @brief 数据埋点回调接口
  */
  class AlivcEventReportListener
  {
  public:

      /**
      *@brief 发送事件
      *@remark
      */
      CONAN_EXTERN
      virtual void OnEventReport(AlivcEventReport* report , std::map<std::string ,std::string> params) = 0;

    /**
    *@brief 数据埋点错误发生
    *@param[in]  report 数据埋点实例
    *@param[in]  errorCode 错误码
    *@remark
    */
    CONAN_EXTERN
    virtual void OnEventReportErrorOccur(AlivcEventReport* report, int errorCode) = 0;

    /**
    *@brief 鉴权信息即将失效
    *@remark 配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息
    */
    CONAN_EXTERN
    virtual void OnStsWillExpireSoon(AlivcEventReport* report, unsigned long afterTime) = 0;

    /**
    *@brief 鉴权信息失效
    *@remark 配置使用外部鉴权信息时会通知鉴权即将过期，调用方需要更新重新请求并更新鉴权信息
    */
    CONAN_EXTERN
    virtual void OnStsExpired(AlivcEventReport* report) = 0;
  };
}
#endif //Alivc_Event_Report_Listener_h
