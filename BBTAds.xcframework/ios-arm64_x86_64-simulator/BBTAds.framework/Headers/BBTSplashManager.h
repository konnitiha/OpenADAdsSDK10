//
//  BBTSplashManager.h
//  testPod
//
//  Created by AI on 2024/3/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BBTSplashDelegate <NSObject>

@optional
//回调已全部转为主线程
/**
 * 广告数据：加载成功
 */
- (void)splashAdDidLoad;

/**
 * 广告数据：加载失败
 * @param error : 错误信息
 */
- (void)splashAdDidFailed:(NSError *)error;

/**
 * 广告成功展示
 */
- (void)splashAdDidVisible;

/**
 * 广告视图：点击
 * @param urlStr 广告落地页链接
 */
- (void)handleAdClick;

/**
 * 落地页或者appstore返回事件
 */
-(void)splashAdDidCloseOtherController;

/**
 * 广告视图：关闭
 */
- (void)splashAdDidShowFinish;

/**
 * 广告成功渲染
 */
- (void)splashAdDidRender;

@end

typedef NS_ENUM(NSInteger, BBTSplashAdStyle) {
    BBTSplashAdStyleImage = 0,    // 普通图片广告
    BBTSplashAdStyleShake = 1,    // 摇一摇广告
    BBTSplashAdStyleSlide = 2     // 滑动广告
};

@interface BBTSplashManager : NSObject

/// 广告回调的代理
@property(nonatomic, weak) id<BBTSplashDelegate> delegate;

/// 获取广告的广告位ID，必传
@property (nonatomic, copy) NSString *mediaId;

/// 用来弹出目标页的ViewController，一般为当前ViewController或root控制器
@property (nonatomic, weak) UIViewController *showAdController;

/// 是否强制竖版开屏，默认为 NO
@property (nonatomic, assign) BOOL portrait;

/// 底部logo视图，用于半屏广告
@property (nonatomic, strong) UIView * _Nullable bottomView;

/// 设置广告样式
- (void)setAdStyle:(BBTSplashAdStyle)style;

/// 发起广告请求并展示在Window中
- (void)loadAndShowSplashAdWithWindow:(UIWindow * _Nullable)window;

/// 展示开屏广告,在广告成功回调 - (void)splashAdDidLoad; 中调用
- (void)showSplashAdWithWindow:(UIWindow * _Nullable)window;

/// 加载广告数据
- (void)loadAdData;

/// 关闭当前展示的开屏广告
- (void)closeSplashAd;

@end

NS_ASSUME_NONNULL_END 
