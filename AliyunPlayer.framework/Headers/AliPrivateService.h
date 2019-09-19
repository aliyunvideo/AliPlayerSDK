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

@end

