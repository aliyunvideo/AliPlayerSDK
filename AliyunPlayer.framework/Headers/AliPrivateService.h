//
//  AliPrivateService.h
//  AliPrivateService
//
//  Created by shiping.csp on 2018/11/16.
//  Copyright © 2018 com.alibaba.AliyunPlayer. All rights reserved.
//

#import <Foundation/Foundation.h>

OBJC_EXPORT
@interface AliPrivateService : NSObject

/**
 @brief 初始化下载秘钥信息
 @param datFile 秘钥文件的路径
 */
/****
 @brief Initialize the credential for downloading resources.
 @param datFile The path of the credential file.
 */
+ (void)initKey:(NSString*)datFile;

/**
 @brief 初始化下载秘钥信息
 @param data 秘钥文件的内容
 */
/****
 @brief Initialize the credential for downloading resources.
 @param data The data of the credential file.
 */
+ (void)initKeyWithData:(NSData*)data;

/**
 @brief  初始化证书服务
 @param key 用户拥有的licenseKey信息
 @param licensePath 本地证书路径
 @param storageDir  下载证书文件夹路径
 */
/****
 @brief Initialize the license service.
 @param key license key that user have
 @param licensePath local license file path
 @param storageDir  download license file folder path
 */
+ (void)initLicenseService;
@end

