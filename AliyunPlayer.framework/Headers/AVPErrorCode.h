#ifndef AVPErrorCode_h
#define AVPErrorCode_h

typedef enum AVPErrorCode: NSUInteger {
    ERROR_SERVER_NO_RESPONSE                                  = 0x20010001,
    ERROR_SERVER_WRONG_JSON                                   = 0x20010002,
    ERROR_NO_MATCH_QUALITY                                    = 0x20010003,
    ERROR_PLAYAUTH_WRONG                                      = 0x20010004,
    ERROR_REQUEST_FAIL                                        = 0x20010005,

    //------------------     POP  begin ------------------------
    ERROR_SERVER_POP_UNKNOWN                                  = 0x20010100,
    ERROR_SERVER_POP_MISSING_PARAMETER                        = 0x20010101,
    ERROR_SERVER_POP_INVALID_PARAMETER                        = 0x20010102,
    ERROR_SERVER_POP_OPERATION_DENIED                         = 0x20010103,
    ERROR_SERVER_POP_OPERATION_SUSPENED                       = 0x20010104,
    ERROR_SERVER_POP_FORBIDDEN                                = 0x20010105,
    ERROR_SERVER_POP_INTERNAL_ERROR                           = 0x20010106,
    ERROR_SERVER_POP_SERVICE_UNAVALIABLE                      = 0x20010107,
    ERROR_SERVER_POP_SIGNATUREANONCE_USED                     = 0x20010108,
    ERROR_SERVER_POP_SECURITYTOKEN_MAILFORMED                 = 0x20010109,
    ERROR_SERVER_POP_SECURITYTOKEN_MISMATCH_ACCESSKEY         = 0x2001010A,
    ERROR_SERVER_POP_SIGNATURE_NOT_MATCH                      = 0x2001010B,
    ERROR_SERVER_POP_ACCESSKEYID_NOT_FOUND                    = 0x2001010C,
    ERROR_SERVER_POP_TOKEN_EXPIRED                            = 0x2001010D,

    //------------------     VOD  begin ------------------------
    ERROR_SERVER_VOD_UNKNOWN                                  = 0x20010200,
    ERROR_SERVER_VOD_FORBIDDEN_ILLEGALSTATUS                  = 0x20010201,
    ERROR_SERVER_VOD_INVALIDVIDEO_NOTFOUND                    = 0x20010202,
    ERROR_SERVER_VOD_INVALIDVIDEO_NOSTREAM                    = 0x20010203,
    ERROR_SERVER_VOD_FORBIDDEN_ALIYUNVODENCRYPTION            = 0x20010204,
    ERROR_SERVER_VOD_INVALIDAUTH_MEDIAID                      = 0x20010205,
    ERROR_SERVER_VOD_INVALIDAUTHINFO_EXPIRETIME               = 0x20010206,

    //------------------     MPS  begin ------------------------
    ERROR_SERVER_MPS_UNKNOWN                                  = 0x20010300,
    ERROR_SERVER_MPS_INVALID_MEDIAID                          = 0x20010301,
    ERROR_SERVER_MPS_INVALID_AUTHTIMEOUT                      = 0x20010302,
    ERROR_SERVER_MPS_INVALID_FORMATS                          = 0x20010303,
    ERROR_SERVER_MPS_INVALID_AUTHINFO                         = 0x20010304,
    ERROR_SERVER_MPS_SIGNATURE_CHECK_FAILED                   = 0x20010305,
    ERROR_SERVER_MPS_MEDIAID_NOT_EXIST                        = 0x20010306,
    ERROR_SERVER_MPS_MEDIA_RESOURCE_NOT_EXIST                 = 0x20010307,
    ERROR_SERVER_MPS_MEDIA_NOT_PUBLISHED                      = 0x20010308,
    ERROR_SERVER_MPS_MEDIA_NOT_ENCRYPTED                      = 0x20010309,
    ERROR_SERVER_MPS_INVALID_CIPHERTEXTBLOB                   = 0x2001030A,
    ERROR_SERVER_MPS_CIPHERBLOB_NOT_EXIST                     = 0x2001030B,
    ERROR_SERVER_MPS_INTERNAL_ERROR                           = 0x2001030C,
    ERROR_SERVER_MPS_INVALID_IDENTITY_NOT_ORDER_VIDEO_SERVICE = 0x2001030D,
    ERROR_SERVER_MPS_UPDATE_CDN_DOMAIN_CONFIGS_FAIL           = 0x2001030E,
    ERROR_SERVER_MPS_AUTH_KEY_EXIST                           = 0x2001030F,
    ERROR_SERVER_MPS_AUTH_KEY_NOT_EXIST                       = 0x20010310,
    ERROR_SERVER_MPS_INVALID_PARAMETER_OUT_OF_BOUND           = 0x20010311,
    ERROR_SERVER_MPS_INVALID_PARAMETER                        = 0x20010312,
    ERROR_SERVER_MPS_INVALID_PARAMETER_NULL_VALUE             = 0x20010313,
    ERROR_SERVER_MPS_INVALID_PARAMETER_EMPTY_VALUE            = 0x20010314,
    ERROR_SERVER_MPS_MEDIA_RESOURCE_NOT_MATCH                 = 0x20010315,
    ERROR_SERVER_MPS_MEDIA_NOT_FOUND_CIPHERTEXT               = 0x20010316,
    ERROR_SERVER_MPS_INVALID_PARAMETER_RAND                   = 0x20010317,
    ERROR_SERVER_MPS_REDIS_POOL_IS_EMPTY                      = 0x20010318,
    ERROR_SERVER_MPS_SIGNATURE_CHECK_MEDIA_FAILED             = 0x20010319,
    ERROR_SERVER_MPS_SIGNATURE_CHECK_EXPIREDTIME_FAILED       = 0x2001031A,
    ERROR_SERVER_MPS_INVALID_SESSION_TIME                     = 0x2001031B,
    ERROR_SERVER_MPS_INVALID_END_USER_ID                      = 0x2001031C,
    ERROR_SERVER_MPS_INVALID_URL                              = 0x2001031D,
    ERROR_SERVER_MPS_HTTP_REQUEST_FAILED                      = 0x2001031E,
    ERROR_SERVER_MPS_XML_FORMAT_ERROR                         = 0x2001031F,
    ERROR_SERVER_MPS_SESSION_NOT_EXIST                        = 0x20010320,
    ERROR_SERVER_MPS_REGION_NOT_SUPPORTED_API                 = 0x20010321,
    ERROR_SERVER_MPS_DRM_NOT_ACTIVATED                        = 0x20010322,
    ERROR_SERVER_MPS_DRM_AUTH_ERROR                           = 0x20010323,
    ERROR_SERVER_MPS_CDN_CONFIG_NOT_EXIST                     = 0x20010324,

    //------------------     LIVESHIFT  begin ------------------------
    ERROR_SERVER_LIVESHIFT_UNKNOWN                            = 0x20010400,
    ERROR_SERVER_LIVESHIFT_REQUEST_ERROR                      = 0x20010401,
    ERROR_SERVER_LIVESHIFT_DATA_PARSER_ERROR                  = 0x20010402,

    //------------------     KEYMANANGER  begin ------------------------
    ERROR_KEYMANAGER_UNKNOWN                                  = 0x20011000,

    //------------------     TBDRM  begin ------------------------
    ERROR_TBDRM_UNKNOWN                                       = 0x20012000,
    ERROR_TBDRM_DEMUXER_UNIMPLEMENTED                         = 0x20012001,

    //------------------     ARTP  begin ------------------------
    ERROR_ARTP_UNKNOWN                                        = 0x20013000,
    ERROR_ARTP_DEMUXER_UNIMPLEMENTED                          = 0x20013001,
    ERROR_ARTP_LOAD_FAILED                                    = 0x20013002,
    ERROR_ARTP_STREAM_ILLEGAL                                 = 0x20013003,
    ERROR_ARTP_STREAM_FORBIDDEN                               = 0x20013004,
    ERROR_ARTP_STREAM_NOT_FOUND                               = 0x20013005,
    ERROR_ARTP_STREAM_STOPPED                                 = 0x20013006,
    ERROR_ARTP_PLAY_TIMEOUT                                   = 0x20013007,
    // use ERROR_ARTP_ARTP_MEDIA_INFO_TIMEOUT instead
    ERROR_ARTP_SPSPPS_AACCONF_TIMEOUT                         = 0x20013008,
    ERROR_ARTP_ARTP_MEDIA_INFO_TIMEOUT                        = ERROR_ARTP_SPSPPS_AACCONF_TIMEOUT,
    ERROR_ARTP_PACKET_RECV_TIMEOUT                            = 0x20013009,
    ERROR_ARTP_MEDIA_PROBE_FAILED                             = 0x2001300A,


    //------------------     UNKNOWN  begin ------------------------
    ERROR_UNKNOWN_ERROR                                       = 0x20020000 - 1,

    // 3、demuxer、datasource模块错误
    // 3. demuxer and datasource module errors.
    ERROR_DEMUXER_START                                       = 0x20030000,
    ERROR_DEMUXER_OPENURL                                     = 0x20030001,
    ERROR_DEMUXER_NO_VALID_STREAM                             = 0x20030002,
    ERROR_DEMUXER_OPENSTREAM                                  = 0x20030003,
    ERROR_LOADING_TIMEOUT                                     = 0x20030004,
    ERROR_DATASOURCE_EMPTYURL                                 = 0x20030005,

    ERROR_DECODE_BASE                                         = 0x20040000,
    ERROR_DECODE_VIDEO                                        = 0x20040001,
    ERROR_DECODE_AUDIO                                        = 0x20040002,

    // 4. network错误
    // 4. Network errors.
    ERROR_NETWORK_UNKNOWN                                     = 0x20050000,
    ERROR_NETWORK_UNSUPPORTED                                 = 0x20050001,
    ERROR_NETWORK_RESOLVE                                     = 0x20050002,
    ERROR_NETWORK_CONNECT_TIMEOUT                             = 0x20050003,
    ERROR_NETWORK_COULD_NOT_CONNECT                           = 0x20050004,
    ERROR_NETWORK_HTTP_403                                    = 0x20050005,
    ERROR_NETWORK_HTTP_404                                    = 0x20050006,
    ERROR_NETWORK_HTTP_4XX                                    = 0x20050007,
    ERROR_NETWORK_HTTP_5XX                                    = 0x20050008,
    ERROR_NETWORK_HTTP_RANGE                                  = 0x20050009,
    ERROR_NETWORK_HTTP_400                                    = 0x2005000A,


    //5. codec 错误
    //5. Codec errors.
    ERROR_CODEC_UNKNOWN                                       = 0x20060000,
    ERROR_CODEC_VIDEO_NOT_SUPPORT                             = 0x20060001,
    ERROR_CODEC_AUDIO_NOT_SUPPORT                             = 0x20060002,

    //6. internal 错误
    //6. Internal errors.
    ERROR_INERNAL_UNKNOWN                                     = 0x20070000,
    ERROR_INERNAL_EXIT                                        = 0x20070001,

    //7.general 错误
    //7. General errors.
    ERROR_GENERAL_UNKNOWN                                     = 0x20080000,
    ERROR_GENERAL_EPERM                                       = 0x20080001,
    ERROR_GENERAL_ENOENT                                      = 0x20080002,
    ERROR_GENERAL_EIO                                         = 0x20080005,

    //
    ERROR_PLAYER_UNKNOWN                                      = 0x30000000 - 1,


    //downloader error code start ......
    DOWNLOADER_ERROR_NOT_SELECT_ITEM                          = 0x30010000,
    DOWNLOADER_ERROR_NO_DOWNLOAD_ITEM                         = 0x30010001,
    DOWNLOADER_ERROR_STS_SOURCE_NULL                          = 0x30010002,
    DOWNLOADER_ERROR_AUTH_SOURCE_NULL                         = 0x30010003,
    DOWNLOADER_ERROR_AUTH_SOURCE_WRONG                        = 0x30010004,
    DOWNLOADER_ERROR_INVALID_ITEM                             = 0x30010005,
    DOWNLOADER_ERROR_URL_CANNOT_REACH                         = 0x30010006,
    DOWNLOADER_ERROR_NOT_SUPPORT_FORMAT                       = 0x30010007,
    DOWNLOADER_ERROR_ENCRYPT_FILE_NOT_MATCH                   = 0x30010008,
    DOWNLOADER_ERROR_DOWNLOAD_SWITCH_OFF                      = 0x30010009,
    DOWNLOADER_ERROR_NET_ERROR                                = 0x3001000A,
    DOWNLOADER_ERROR_NOT_SET_SAVE_DIR                         = 0x3001000B,
    DOWNLOADER_ERROR_CANNOT_CREATE_SAVE_DIR                   = 0x3001000C,
    DOWNLOADER_ERROR_NO_SPACE                                 = 0x3001000D,
    DOWNLOADER_ERROR_WRITE_ERROR                              = 0x3001000E,
    DOWNLOADER_ERROR_ENCRYPT_ERROR                            = 0x3001000F,
    DOWNLOADER_ERROR_FILE_NOT_EXIST                           = 0x30010010,
    DOWNLOADER_ERROR_CLEAN_INVALID_PARAM                      = 0x30010011,
    DOWNLOADER_ERROR_CLEAN_WRONG_STATUS                       = 0x30010012,
    DOWNLOADER_ERROR_GET_AES_KEY_FAIL                         = 0x30010013,
    DOWNLOADER_ERROR_ENCRYPTION_NOT_SUPPORT                   = 0x30010014,
} AVPErrorCode;

/**@brief 播放器事件类型，带描述字符串*/
/****@brief Player event type with a description string.*/
typedef enum AVPEventWithString: NSUInteger {
    /**@brief 设置了硬解，但是切换为软解。额外信息为描述信息。*/
    /****@brief Hardware decoding is switched to software decoding. Additional information: description.*/
    EVENT_SWITCH_TO_SOFTWARE_DECODER = 100,
    /**@brief 音频解码格式不支持。额外信息为描述信息。*/
    /****@brief Audio decoding does not support the specified format. Additional information: description.*/
    EVENT_AUDIO_CODEC_NOT_SUPPORT    = 101,
    /**@brief 音频解码器设备失败。额外信息为描述信息。*/
    /****@brief The audio decoder failed. Additional information: description.*/
    EVENT_AUDIO_DECODER_DEVICE_ERROR = 102,
    /**@brief 视频解码格式不支持。额外信息为描述信息。*/
    /****@brief Video decoding does not support the specified format. Additional information: description.*/
    EVENT_VIDEO_CODEC_NOT_SUPPORT    = 103,
    /**@brief 视频解码器设备失败。额外信息为描述信息。*/
    /****@brief The video decoder failed. Additional information: description.*/
    EVENT_VIDEO_DECODER_DEVICE_ERROR = 104,
    /**@brief 视频渲染设备初始化失败。额外信息为描述信息。*/
    /****@brief The video renderer failed. Additional information: description.*/
    EVENT_VIDEO_RENDER_INIT_ERROR    = 105,

    /**@brief Demuxer trace ID for artp*/
    EVENT_PLAYER_DEMUXER_TRACE_ID    = 106,
    /**@brief 网络失败，需要重试。无额外信息。*/
    /****@brief Network connection failed. Try again. No additional information is provided.*/
    EVENT_PLAYER_NETWORK_RETRY       = 108,
    /**@brief 缓存成功。无额外信息。*/
    /****@brief Content cached. No additional information is provided.*/
    EVENT_PLAYER_CACHE_SUCCESS       = 109,
    /**@brief 缓存失败。额外信息为描述信息。*/
    /****@brief Failed to cache the content. Additional information: description.*/
    EVENT_PLAYER_CACHE_ERROR         = 110,
    /**@brief 系统无可用内存来存放媒体数据。*/
    /****@brief The system does not have memory to store the media data.*/
    EVENT_PLAYER_LOW_MEMORY          = 111,
} AVPEventWithString;

#endif

