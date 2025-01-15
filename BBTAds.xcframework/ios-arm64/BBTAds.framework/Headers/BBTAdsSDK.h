#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BBTAdsSDK : NSObject

/// SDK 版本号
+ (NSString *)version;

/// 注册 SDK
/// @param appId 应用ID
/// @param mediaId 媒体ID 
+ (void)registerWithAppId:(NSString *)appId mediaId:(NSString *)mediaId secret:(NSString *)secret;

/// 是否已经初始化
+ (BOOL)isInitialized;

/// 设置测试模式
/// @param isTest 是否为测试模式
+ (void)setTestMode:(BOOL)isTest;

/// 获取当前测试模式状态
+ (BOOL)isTestMode;

/// 设置日志开关
/// @param enabled 是否开启日志
+ (void)setLogEnabled:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
