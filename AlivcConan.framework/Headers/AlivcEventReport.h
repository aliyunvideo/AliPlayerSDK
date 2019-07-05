#ifndef Alivc_Event_Report_h
#define Alivc_Event_Report_h

#include "AlivcConanExport.h"
#include "AlivcEventReportConfig.h"
#include "AlivcEventReportListener.h"

namespace AlivcConan
{
  /*
  @brief 数据埋点接口类
  */
  class AlivcEventReport
  {
  public:
    /**
    *@brief 创建数据埋点实例
    *@param[in] config 数据埋点实例配置
    */
    CONAN_EXTERN
    static AlivcEventReport* CreateEventReport(AlivcEventReportConfig config);

    /**
    *@brief 通过id查找数据埋点实例
    */
    CONAN_EXTERN
    static AlivcEventReport* GetEventReportById(long long id);

    /**
    *@brief 释放数据埋点实例
    *@param[in]
    *@remark 调用释放后不可在操作此数据埋点实例
    */
    CONAN_EXTERN
    static void Release(AlivcEventReport* eventReport);

    /**
    *@brief 初始化埋点信息（鉴权信息）
    *@param[in]
    *@remark
    */
    CONAN_EXTERN
    virtual void Init() = 0;

    /**
    *@brief 获取埋点实例Id
    *@return 埋点实例Id
    *@remark
    */
    CONAN_EXTERN
    virtual long long GetId() = 0;

    /**
    *@brief 设置埋点公共参数
    *@param[in]  param 埋点公共参数
    *@remark
    */
    CONAN_EXTERN
    virtual int SetPublicParam(const char* param) = 0;

    /**
    *@brief 更新埋点公共参数
    *@param[in]  key 更新埋点键值
    *@param[in]  value 更新埋点键值
    *@remark
    */
    CONAN_EXTERN
    virtual int UpdatePublicParam(const char* key, const char* value) = 0;

    /**
    *@brief 设置数据埋点事件回调
    *@param[in]  listener 数据埋点监听器
    *@remark
    */
    CONAN_EXTERN
    virtual void SetEventReportListener(AlivcEventReportListener* listener) = 0;

    /**
    *@brief 发送数据埋点
    *@param[in]  eventId 埋点事件Id
    *@param[in]  param 埋点数据
    *@param[in]  flush 是否立即发送
    *@remark
    */
    CONAN_EXTERN
    virtual int SendEvent(int eventId, const char* param, bool flush = false) = 0;

    /**
    *@brief 发送数据埋点
    *@param[in]  eventId 埋点事件Id
    *@param[in]  flush 是否立即发送
    *@param[in]  fmt... 埋点args字段格式及内容
    *@remark
    */
    CONAN_EXTERN
    virtual int SendEvent(int eventId, bool flush, const char *fmt, ...) = 0;

    /**
    *@brief 重新设置SLS鉴权信息
    *@param[out]
    *@param[in]  const char * accessKey  SLS服务accessId
    *@param[in]  const char * secretKey  SLS服务accessKey
    *@param[in]  const char * securityToken  STS动态Token鉴权
    *@param[in]  const char * expireTime  STS鉴权信息过期时间
    *@remark 使用外部鉴权时鉴权到期需要重新设置
    */
    CONAN_EXTERN
    virtual int ResetAcessTokenInfo(const char* accessKey, const char* secretKey, const char* securityToken, const char* expireTime) = 0;
    
    /**
     *@brief 发送崩溃埋点信息及释放底层实例
     *@param[in]  eventId 埋点事件Id
     *@param[in]  param 埋点数据
     *@remark
     */
    CONAN_EXTERN
    virtual int SendCrashEventAndRelease(int eventId, const char* param) = 0;

  protected:
    AlivcEventReport(AlivcEventReportConfig config) {}
    virtual ~AlivcEventReport() {}
  };

}

#endif //Alivc_Event_Report_h
