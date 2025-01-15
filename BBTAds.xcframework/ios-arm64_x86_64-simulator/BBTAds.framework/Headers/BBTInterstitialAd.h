#import <UIKit/UIKit.h>
#import "BBTInterstitialManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface BBTInterstitialAd : NSObject

@property (nonatomic, weak) id<BBTInterstitialDelegate> delegate;
@property (nonatomic, copy) NSString *mediaId;
@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, readonly) BOOL isReady;
@property (nonatomic, readonly) UIView *adView;

// 初始化方法
- (instancetype)initWithMediaId:(NSString *)mediaId;

// 设置广告数据
- (void)setupWithAdData:(NSDictionary *)adData;

// 展示广告
- (void)showFromViewController:(UIViewController *)viewController;

// 关闭广告
- (void)dismissWithAutoClose:(BOOL)autoClose;

@end

NS_ASSUME_NONNULL_END 
