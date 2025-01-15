#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BBTFeedAdStyle) {
    BBTFeedAdStylePureImage,        // 纯图片样式
    BBTFeedAdStyleImageText,        // 图文样式
    BBTFeedAdStyleTextImage,        // 文图样式
    BBTFeedAdStyleLargeImage,       // 大图样式
    BBTFeedAdStyleMixed,           // 混合样式
    BBTFeedAdStyleTextOverlay,     // 文字浮层样式
    BBTFeedAdStyleThreeImages,     // 三图样式
    BBTFeedAdStyleLeftImageRightText, // 左图右文样式
    BBTFeedAdStyleLeftTextRightImage  // 左文右图样式
};

// 添加广告样式常量定义
extern NSString *const BBTAdStyleXDT;
extern NSString *const BBTAdStyleOther; // 其他样式常量

@interface BBTFeedAdData : NSObject

@property (nonatomic, copy) NSString *adId;            // 广告唯一标识
@property (nonatomic, copy) NSString *title;           // 广告标题
@property (nonatomic, copy) NSString *desc;            // 广告描述
@property (nonatomic, strong) NSArray *imageUrls;      // 广告图片URL数组
@property (nonatomic, copy) NSString *h5url;        // 点击跳转URL
@property (nonatomic, copy) NSString *deepLinkUrl;    // 点击跳转URL
@property (nonatomic, copy) NSString *sourceLogo;      // 广告Logo
@property (nonatomic, copy) NSString *source;           // 广告来源
@property (nonatomic, assign) BBTFeedAdStyle style;    // 广告样式
@property (nonatomic, copy) NSArray *viewUrl3rd;       // 曝光上报URL数组
@property (nonatomic, copy) NSArray *clickUrl3rd;      // 点击上报URL数组
@property (nonatomic, copy) NSArray *dpEventUrls;      // 点击上报URL数组

@end

NS_ASSUME_NONNULL_END 
