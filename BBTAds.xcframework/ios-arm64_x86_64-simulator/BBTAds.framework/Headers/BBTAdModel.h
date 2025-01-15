#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 广告类型
typedef NS_ENUM(NSInteger, BBTAdCreativeType) {
    BBTAdCreativeTypeUnknown = 0,    // 未知类型
    BBTAdCreativeTypeImage = 1,      // 图片广告
    BBTAdCreativeTypeVideo = 2,      // 视频广告
    BBTAdCreativeTypeHTML = 3,       // HTML广告
    BBTAdCreativeTypeText = 4        // 文字广告
};

@interface BBTAdModel : NSObject

#pragma mark - 基础属性
@property (nonatomic, copy) NSString *adId;              // 广告ID
@property (nonatomic, copy) NSString *creativeId;        // 创意ID
@property (nonatomic, assign) BBTAdCreativeType type;    // 广告类型
@property (nonatomic, assign) CGSize size;               // 广告尺寸
@property (nonatomic, copy) NSString *adCate;            // 广告类目
@property (nonatomic, copy) NSString *adBrand;           // 广告品牌

#pragma mark - 广告内容
@property (nonatomic, copy) NSString *title;             // 标题
@property (nonatomic, copy) NSString *description;       // 描述
@property (nonatomic, copy) NSString *imageUrl;          // 主图URL
@property (nonatomic, copy) NSString *iconUrl;           // 图标URL
@property (nonatomic, copy) NSString *videoUrl;          // 视频URL
@property (nonatomic, copy) NSString *clickUrl;          // 点击跳转URL
@property (nonatomic, copy) NSString *deepLinkUrl;       // DeepLink URL
@property (nonatomic, copy) NSString *landingPageUrl;    // 落地页URL
@property (nonatomic, copy) NSString *callToAction;      // 行动按钮文案

#pragma mark - 广告主信息
@property (nonatomic, copy) NSString *advertiserName;    // 广告主名称
@property (nonatomic, copy) NSString *advertiserLogo;    // 广告主logo

#pragma mark - 监测相关
@property (nonatomic, copy) NSArray<NSString *> *impressionUrls;    // 曝光监测URLs
@property (nonatomic, copy) NSArray<NSString *> *clickUrls;         // 点击监测URLs
@property (nonatomic, copy) NSArray<NSString *> *startUrls;         // 开始播放监测URLs
@property (nonatomic, copy) NSArray<NSString *> *completeUrls;      // 播放完成监测URLs

#pragma mark - 初始化方法
- (instancetype)initWithDictionary:(NSDictionary *)dict;
+ (instancetype)modelWithDictionary:(NSDictionary *)dict;

#pragma mark - 工具方法
- (BOOL)isValid;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
