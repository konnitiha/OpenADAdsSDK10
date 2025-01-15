//
//  BBTInterstitialManager.h
//  testPod
//
//  Created by AI on 2024/3/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BBTInterstitialDelegate <NSObject>

@optional
//回调已全部转为主线程
/**
 * 广告数据：加载成功
 */
- (void)interstitialAdDidLoad;

/**
 * 广告数据：加载失败
 * @param error : 错误信息
 */
- (void)interstitialAdDidFailed:(NSError *)error;

/**
 * 广告视图：展示
 */
- (void)interstitialAdDidVisible;

/**
 * 广告视图：点击
 */
- (void)interstitialAdDidClick;

/**
 * 落地页或者appstore返回事件
 */
- (void)interstitialAdDidCloseOtherController;

/**
 * 广告视图：关闭
 */
- (void)interstitialAdDidAutoClose:(BOOL)autoClose;

@end


@interface BBTInterstitialManager : NSObject

@property (nonatomic, copy) NSString *mediaId;

@property (nonatomic, weak) UIViewController *showAdController;

//@property (nonatomic, strong) SFVideoConfig *videoConfig;

/// 广告回调的代理
@property(nonatomic, weak) id<BBTInterstitialDelegate> delegate;

/// 定时自动关闭插屏，默认由平台控制
@property (nonatomic) double autoCloseTime;

/// 展示插屏广告
- (void)showInterstitialAd;

/// 加载广告数据
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END 
