#ifndef Alivc_Event_Report_Config_h
#define Alivc_Event_Report_Config_h

#include <string>
#include <map>
#include "AlivcConanDefine.h"
#include "AlivcConanExport.h"


namespace AlivcConan
{
  const static char* PAIR_SEPARATOR = " *||* ";
  const static char* KEY_VALUE_SEPARATOR = " * ";

//  /*
//  *@brief 将埋点参数转换为字符串
//  *@param[in]  params埋点参数键值对map
//  *@remark 示例:传入原始埋点键值对Map,形如
//  *            [key1] = [value1]
//  *            [key2] = [value2]
//  *            [key2] = [value3]
//  拼接后字符串形式为： "key1 * value1 *||* key2 * value2 *||* key3 * value3"
//  */
//  static std::string ConvertEventParam(const std::map<std::string, std::string>& params)
//  {
//    if (params.empty())
//    {
//      return std::string("");
//    }
//
//    std::string strParams;
//    size_t idx = 0;
//    size_t pair_count = params.size();
//    for (auto iter = params.begin(); iter != params.end(); iter++)
//    {
//      if (iter->first.empty())
//      {
//        continue;
//      }
//
//      strParams += iter->first;
//      strParams += KEY_VALUE_SEPARATOR;
//      strParams += iter->second;
//
//      if (idx < pair_count - 1)
//      {
//        strParams += PAIR_SEPARATOR;
//      }
//
//      idx++;
//    }
//
//    return strParams;
//  }

  /*
  @brief 数据埋点实例配置类
  */
  class AlivcEventReportConfig
  {
  public:
      CONAN_EXTERN AlivcEventReportConfig() {}
      CONAN_EXTERN ~AlivcEventReportConfig() {}

    const char* mClientID { nullptr };                            //设备唯一Id（UUID)
    const char* mTerminalType{ nullptr };                         //终端类型,如pc，pad，iphone，andorid
    const char* mDeviceModel{ nullptr };                          //设备型号，如iPhone8
    BusinessType mBussinessType;                                  //业务类型

    bool mUseExternalAuth{ false };                               //是否使用外部鉴权(默认内部根据业务类型获取鉴权信息，如需外部自主获取鉴权，需开启此配置)
    const char* mEndPoint{ nullptr };                             //SLS服务endpoint(使用外部鉴权时必须设置)
    const char* mProjectName{ nullptr };                          //SLS服务project(使用外部鉴权时必须设置)
    const char* mLogStore{ nullptr };                             //SLS服务logstore(使用外部鉴权时必须设置)
    const char* accessKey{ nullptr };                             //SLS服务鉴权信息accessKey(使用外部鉴权时必须设置)
    const char* secretKey{ nullptr };                             //SLS服务鉴权信息secretKey(使用外部鉴权时必须设置)
    const char* securityToken{ nullptr };                         //SLS服务鉴权信息securityToken(使用外部鉴权时必须设置)
    const char* strExpireTime{ nullptr };                         //SLS服务鉴权信息strExpireTime(使用外部鉴权时必须设置)
    const char* mConanVersion{nullptr};
  };
}

#endif //Alivc_Event_Report_Config_h
