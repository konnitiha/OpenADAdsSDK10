#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BBTNativeAdModel : NSObject <NSCopying>

#pragma mark - 广告基本信息
@property (nonatomic, copy, nullable) NSString *title;           // 广告标题
@property (nonatomic, copy, nullable) NSString *desc;            // 广告描述
@property (nonatomic, copy, nullable) NSString *imageUrl;        // 主图URL
@property (nonatomic, copy, nullable) NSString *iconUrl;         // 图标URL
@property (nonatomic, copy, nullable) NSString *callToAction;    // 行动按钮文案
@property (nonatomic, copy, nullable) NSString *advertiser;      // 广告主名称
@property (nonatomic, copy, nullable) NSString *landingPageUrl;  // 落地页URL

#pragma mark - 多媒体资源
@property (nonatomic, copy, nullable) NSArray<NSString *> *imageUrls;  // 多图资源

#pragma mark - 监测相关
@property (nonatomic, copy, nullable) NSArray<NSString *> *impressionUrls;  // 曝光监测
@property (nonatomic, copy, nullable) NSArray<NSString *> *clickUrls;       // 点击监测

#pragma mark - 初始化方法
- (nullable instancetype)initWithDictionary:(nullable NSDictionary *)dict;
+ (nullable instancetype)modelWithDictionary:(nullable NSDictionary *)dict;

#pragma mark - 工具方法
- (BOOL)isValid;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END 