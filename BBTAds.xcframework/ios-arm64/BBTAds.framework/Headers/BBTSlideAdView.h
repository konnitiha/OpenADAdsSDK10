#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "BBTSplashManager.h"

@interface BBTSlideAdView : UIView

@property (nonatomic, weak) id<BBTSplashDelegate> delegate;  // 广告代理
@property (nonatomic, strong) UIImageView *adImageView;      // 广告图片
@property (nonatomic, strong) AVPlayerLayer *videoPlayerLayer;  // 视频播放层
@property (nonatomic, strong) AVPlayer *videoPlayer;         // 视频播放器
@property (nonatomic, strong) UIButton *skipButton;          // 跳过按钮
@property (nonatomic, strong) UIView *slideHintView;         // 滑动提示容器
@property (nonatomic, strong) UIImageView *slideIconView;    // 滑动方向图标
@property (nonatomic, strong) UIImageView *slideFingerView;  // 滑动手指图标
@property (nonatomic, strong) UILabel *slideHintLabel;       // 滑动提示文本
@property (nonatomic, assign) BOOL isVideoAd;               // 是否为视频广告


// 更新跳过按钮倒计时
- (void)updateSkipButtonWithTime:(NSInteger)seconds;

// 设置图片广告内容
- (void)setupWithImageUrl:(NSString *)imageUrl 
               slideHint:(NSString *)slideHint
               source:(NSString *)source
               sourceLogo:(NSString *)sourceLogo;

// 设置视频广告内容
- (void)setupWithVideoUrl:(NSString *)videoUrl
               slideHint:(NSString *)slideHint;

// 清理视频资源
- (void)cleanupVideoResources;

@end 
