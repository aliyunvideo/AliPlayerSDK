//
// Created by SuperMan on 2021/12/1.
//

#import <Foundation/Foundation.h>


@interface AVPFilterOptions : NSObject

- (void)setOptions:(NSString *)key value:(NSObject *)value;

- (NSString *)toJSONStr;

@end

@interface AVPFilter : NSObject

- (instancetype)initWithTarget:(NSString *)target;

- (void)setOptions:(AVPFilterOptions *)options;

@end


@interface AVPFilterConfig : NSObject

- (void)addFilter:(AVPFilter *)filter;

- (NSString *)toJSONStr;

@end
