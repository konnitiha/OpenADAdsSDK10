#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 权限信息
@interface BBTPermissionEntry : NSObject
@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *value;
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

// App合规信息
@interface BBTAppComplianceInfo : NSObject
@property (nonatomic, copy) NSString *name;              // 应用中文名
@property (nonatomic, copy) NSString *version;           // 应用版本号码
@property (nonatomic, copy) NSString *developer;         // 开发者
@property (nonatomic, copy) NSString *privacyUrl;        // 隐私协议网址
@property (nonatomic, strong) NSArray<BBTPermissionEntry *> *permissionList;  // 权限列表
@property (nonatomic, copy) NSString *permissionsUrl;    // 权限URL
@property (nonatomic, copy) NSString *functionDescUrl;   // 功能描述URL
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

// App信息
@interface BBTAppInfo : NSObject
@property (nonatomic, copy) NSString *name;              // APP中文名称
@property (nonatomic, copy) NSString *desc;              // APP文字描述
@property (nonatomic, copy) NSString *version;           // APP版本号
@property (nonatomic, copy) NSString *packageName;       // APP包名
@property (nonatomic, strong) BBTAppComplianceInfo *appComplianceInfo;  // 合规六要素
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

// 图片信息
@interface BBTImgInfo : NSObject
@property (nonatomic, copy) NSString *type;              // 素材类型标记，"IMG"
@property (nonatomic, copy) NSString *url;               // 图片地址
@property (nonatomic, assign) int width;                 // 图片宽
@property (nonatomic, assign) int height;                // 图片高
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

// 文本信息
@interface BBTTxtInfo : NSObject
@property (nonatomic, copy) NSString *type;              // 素材类型标记，"TXT"
@property (nonatomic, copy) NSString *content;           // 文本信息
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

// URL信息
@interface BBTUrlInfo : NSObject
@property (nonatomic, copy) NSString *type;              // 素材类型标记，"URL"
@property (nonatomic, copy) NSString *h5url;             // H5地址落地页
@property (nonatomic, copy) NSString *deepLinkUrl;       // 原生地址落地页
- (instancetype)initWithDictionary:(NSDictionary *)dict;
@end

// 监控信息
@interface BBTTrackInfo : NSObject
@property (nonatomic, strong) NSArray<NSString *> *viewUrl3rd;      // 曝光监测地址数组
@property (nonatomic, strong) NSArray<NSString *> *clickUrl3rd;     // 点击监测地址数组
@property (nonatomic, strong) NSArray<NSString *> *conversionUrls;  // 转化监测地址
@property (nonatomic, strong) NSArray<NSString *> *dpEventUrls;     // deeplink唤起事件监测地址
- (instancetype)initWithDictionary:(NSDictionary *)dict;
// 加密价格宏
- (NSArray<NSString *> *)encryptPriceMacro:(NSArray<NSString *> *)urls price:(NSString *)price;
@end

// 广告信息
@interface BBTAdInfo : NSObject
@property (nonatomic, copy) NSString *settlePrice;       // 价格参数，单位是分
@property (nonatomic, copy) NSString *positionId;        // 广告位置信息
@property (nonatomic, copy) NSString *templateFlag;      // 模板标记
@property (nonatomic, strong) BBTTrackInfo *trackInfo;   // 监控信息
@property (nonatomic, strong) NSArray<BBTImgInfo *> *images;    // 图片类素材数组
@property (nonatomic, strong) NSArray<BBTTxtInfo *> *texts;     // 文本类素材数组
@property (nonatomic, strong) NSString *sourceLogo;
@property (nonatomic, strong) NSString *sourceName;
@property (nonatomic, strong) NSString *adId;
@property (nonatomic, strong) NSString *adCate;
@property (nonatomic, strong) NSString *adBrand;
@property (nonatomic, strong) NSString *adStyle;
@property (nonatomic, strong) BBTUrlInfo *urlInfo;       // 落地页对象
@property (nonatomic, strong) BBTAppInfo *appInfo;       // APP信息
- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)toDictionary;
@end

// 广告响应
@interface BBTAdsResponse : NSObject
@property (nonatomic, copy) NSString *requestId;         // 请求ID，和入参的id保持一致
@property (nonatomic, copy) NSString *message;           // 提示信息
@property (nonatomic, assign) int code;                  // 返回码，200-正常，500-异常
@property (nonatomic, strong) NSArray<BBTAdInfo *> *data;// 广告对象数组

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)toDictionary;
- (BOOL)isValid;
@end

// 广告响应工厂类
@interface BBTAdsResponseFactory : NSObject
+ (nullable BBTAdsResponse *)createFromServerResponse:(NSDictionary *)response;
+ (BBTAdsResponse *)createErrorResponseWithCode:(int)code message:(NSString *)message;
@end

NS_ASSUME_NONNULL_END 
