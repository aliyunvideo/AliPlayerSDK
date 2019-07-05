#ifndef Alivc_Conan_Error_h
#define Alivc_Conan_Error_h

namespace AlivcConan
{
  /**
  @brief 错误码
  */
  enum ErrorCode
  {
    OK = 0,                       //正常
    ParameterError = -1,          //参数错误
    InitFailed = -2,              //初始化失败
    StateError = -3,              //状态错误
    OpenFileFailed = -4,          //打开文件失败
    CloseFileFailed = -5,         //关闭文件失败
    CreateFileFailed = -6,        //创建文件失败
    CreateLogDirFailed = -7,      //创建日志文件夹失败
    OpenLogDirFailed = -8,        //读取日志文件夹失败
    ReadFileError = -9,           //读文件错误
    WriteFileError = -10,         //写文件错误
    UploadFailed = -11,           //上传文件失败
    CompressFileFailed = -12,     //压缩日志文件失败
    LogFileSizeOverLimit = -13,   //日志文件大小超过上传限制
    RequestStsFailed = -14,       //请求鉴权信息失败
    NetworkStateError = -15,      //网络状态错误
    StsInfoInvaild = -16,         //鉴权信息无效
    SendEventFailed = -17,        //发送埋点失败
    ParseStsInfoFailed = -18,     //解析STS信息失败
    EventCacheFull = -19,         //埋点缓存队列满
  };
}
#endif //Alivc_Conan_Error_h