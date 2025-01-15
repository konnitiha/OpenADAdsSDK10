#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// ShakeSlopArg 摇一摇/前倾灵敏度参数
@interface BBTShakeSlopArg : NSObject

@property (nonatomic, assign) int startHour;     // 开始小时 0-24
@property (nonatomic, assign) int endHour;       // 结束小时 0-24
@property (nonatomic, assign) int sensitivity;   // 灵敏度等级 1-10，1最灵敏，10最不灵敏

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)toDictionary;

@end

// InteractionCtrlArg 交互控制参数对象
@interface BBTInteractionCtrlArg : NSObject

@property (nonatomic, assign) int adType;            // 1-开屏 2-插屏 3-信息流
@property (nonatomic, assign) int supportSelfRender; // 0-不支持 1-支持 默认0
@property (nonatomic, assign) int canSkip;           // 1-可跳过 0-不可跳过 默认0
@property (nonatomic, assign) int skipType;          // 0-5秒倒计时 1-3秒倒计时 2-圆形倒计时 默认0
@property (nonatomic, assign) int canClose;          // 0-可关 1-不可关 默认0
@property (nonatomic, assign) int closeType;         // 0-一直显示 1-3秒后显示 2-5秒后显示 默认0
@property (nonatomic, assign) int closeBtnPos;       // 1-左上角 0-右上角 2-右下角 3-左下角 4-正中 默认0
@property (nonatomic, assign) int autoPlay;          // 0-不自动播放 1-仅wifi自动播放 2-自动播放 默认0
@property (nonatomic, assign) int clickTriggerType;  // 0-点击 1-摇一摇 2-前倾 3-滑动 默认0
@property (nonatomic, strong) NSArray<BBTShakeSlopArg *> *shakeArgs;  // 摇一摇灵敏度参数数组
@property (nonatomic, strong) NSArray<BBTShakeSlopArg *> *slopArgs;   // 前倾灵敏度参数数组
@property (nonatomic, assign) int clickArea;         // 0-整个区域可点 1-指定区域可点 默认0

- (instancetype)initWithDictionary:(NSDictionary *)dict;
- (NSDictionary *)toDictionary;

@end

// FreqCtrlArg 频控参数对象
@interface BBTFreqCtrlArg : NSObject

@property (nonatomic, assign) int reqDaily;      // 设备日请求上限
@property (nonatomic, assign) int expDaily;      // 设备日曝光上限
@property (nonatomic, assign) int clkDaily;      // 设备日点击上限
@property (nonatomic, assign) int reqHouly;      // 设备小时请求上限
@property (nonatomic, assign) int expHouly;      // 设备小时曝光上限
@property (nonatomic, assign) int clkHouly;      // 设备小时点击上限
@property (nonatomic, assign) int expInterval;   // 设备广告展示时间间隔，单位秒

// 使用字典初始化
- (instancetype)initWithDictionary:(NSDictionary *)dict;
// 转换为字典
- (NSDictionary *)toDictionary;

@end

// 广告请求回调
typedef void(^BBTAdRequestSuccessBlock)(NSDictionary *response);
typedef void(^BBTAdRequestFailureBlock)(NSError *error);

@interface BBTAdsManager : NSObject

/// 单例方法
+ (instancetype)sharedInstance;

/// 初始化方法
/// @param appId 应用ID
/// @param mediaId 媒体ID
/// @param secret 密钥
- (void)initializeWithAppId:(NSString *)appId mediaId:(NSString *)mediaId secret:(NSString *)secret;

/// 请求广告
/// @param positionId 广告位置ID
/// @param bidPrice 广告底价(分)
/// @param success 成功回调
/// @param failure 失败回调
- (void)requestAdWithPositionId:(NSString *)positionId 
                     bidPrice:(double)bidPrice
                     success:(BBTAdRequestSuccessBlock)success
                     failure:(BBTAdRequestFailureBlock)failure;

/// 设置测试模式
/// @param isTest 是否为测试模式
- (void)setTestMode:(BOOL)isTest;

/// 设置日志开关
/// @param enabled 是否开启日志
- (void)setLogEnabled:(BOOL)enabled;

/// 获取当前 AppId
- (NSString *)currentAppId;

/// 获取当前 MediaId
- (NSString *)currentMediaId;

/// 清理缓存数据
- (void)clearCache;

/// 获取频控参数
- (BBTFreqCtrlArg *)getFreqCtrlArg;

/// 更新频控参数
/// @param freqCtrlArg 频控参数对象
- (void)updateFreqCtrlArg:(BBTFreqCtrlArg *)freqCtrlArg;

/// 获取交互控制参数
- (BBTInteractionCtrlArg *)getInteractionCtrlArg;

/// 更新交互控制参数
/// @param interactionCtrlArg 交互控制参数对象
- (void)updateInteractionCtrlArg:(BBTInteractionCtrlArg *)interactionCtrlArg;

/// 发送广告负反馈
/// @param negType 负反馈类型：1-直接关闭，2-类别负反馈，3-品牌负反馈，4-广告负反馈
/// @param bizId 负反馈唯一标识：
///             negType=1或4时，填充广告唯一标识(adId)
///             negType=2时，填充广告分类唯一标识(adCate)
///             negType=3时，填充品牌唯一标识(adBrand)
/// @param ext 预留扩展参数
/// @param completion 完成回调，success表示是否成功，error包含错误信息
- (void)sendNegativeFeedbackWithType:(NSInteger)negType 
                             bizId:(NSString *)bizId 
                               ext:(nullable NSDictionary *)ext 
                       completion:(nullable void(^)(BOOL success, NSError * _Nullable error))completion;

///// 设置广告请求基础URL
///// @param baseUrl 基础URL地址，例如：https://adx.babytree.com
//- (void)setBaseUrl:(NSString *)baseUrl;

/// 获取当前广告请求基础URL
//- (NSString *)currentBaseUrl;

@end

NS_ASSUME_NONNULL_END
