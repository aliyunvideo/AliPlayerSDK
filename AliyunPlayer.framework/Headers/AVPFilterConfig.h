//
// Created by SuperMan on 2021/12/1.
//

#import <Foundation/Foundation.h>


@interface AVPFilterOptions : NSObject
/**
 @brief 设置滤镜参数
*/
/****
 @brief Set filter options
*/
- (void)setOptions:(NSString *)key value:(NSObject *)value;

- (NSString *)toJSONStr;

@end


@interface AVPFilter : NSObject
/**
 @brief 创建滤镜
 @param target 目标滤镜
 */
/****
 @brief Init filter
 @param target filter target
*/
- (instancetype)initWithTarget:(NSString *)target;

/**
 @brief 设置滤镜参数
 @param options
 */
/****
 @brief Set filter options
 @param options
*/
- (void)setOptions:(AVPFilterOptions *)options;

@end


@interface AVPFilterConfig : NSObject

/**
 @brief 添加滤镜
 @param filter
 */
/****
 @brief Add filter
 @param filter
*/
- (void)addFilter:(AVPFilter *)filter;

- (NSString *)toJSONStr;

@end
