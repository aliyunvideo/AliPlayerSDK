//
//  AlivcCrashConfig.h
//  AlivcConanStatic
//
//  Created by lyz on 2018/11/20.
//  Copyright © 2018年 Aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlivcConanConstans.h"

OBJC_EXPORT
@interface AlivcCrashConfig : NSObject


/**
 AlivcEventReport ID
 * AlivcEventReport init之后可以获得此Id
 * 若不设置此id，则crash模块不会上传埋点事件
 */
@property (nonatomic, assign) long long eventReportId;


/**
 AlivcLog ID
 * AlivcLog init之后可以获得此Id
 * 若不设置此id，则crash模块不会上报crash文件
 */
@property (nonatomic, assign) long long logId;


/**
 crash 过滤字段
 * 建议给定当前SDK的名称，crash模块会根据抓取到的crash堆栈与此字段进行匹配
   若堆栈被包含此字段，则认定为匹配成功，crash执行上报逻辑
 * 支持多个crashFilter，可以通过AlivcCrashHandle进行增删操作
 */
@property (nonatomic, copy) NSString *crashFilter;


/**
 各个SDK关联用Id
 */
@property (nonatomic, copy) NSString *traceId;


/**
 crash文件保存路径
 * 默认 : Library-Caches-AlivcConanCrash
 * 注意 : 此处给定文件夹路径，尽量不要动态修改此文件夹路径，因为crash文件上报是下一次初始化的时候执行上报，如果文件夹变更了，没法匹配crash文件
 */
@property (nonatomic, copy) NSString *crashFileSavePath;


/**
 业务类型
 * 默认 : None
 * 必选参数，否则无法上报crash文件
 */
@property (nonatomic, assign) AlivcConanBusinessType businessType;

@end
