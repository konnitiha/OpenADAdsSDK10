#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol BBTAdViewDelegate <NSObject>

@optional
- (void)adViewDidClick;      // 广告被点击
- (void)adViewDidClose;      // 广告被关闭
- (void)adViewDidExposure:(UIView *)adView;   // 广告曝光

@end 
