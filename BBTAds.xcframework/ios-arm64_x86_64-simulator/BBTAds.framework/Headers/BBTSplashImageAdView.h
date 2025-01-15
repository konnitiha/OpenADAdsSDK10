#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "BBTSplashManager.h"

@interface BBTSplashImageAdView : UIView

@property (nonatomic, strong) UIImageView *adImageView;      // 广告图片
@property (nonatomic, strong) AVPlayerLayer *videoPlayerLayer;  // 视频播放层
@property (nonatomic, strong) AVPlayer *videoPlayer;         // 视频播放器
@property (nonatomic, strong) UIButton *skipButton;          // 跳过按钮
@property (nonatomic, strong) UILabel *actionTipLabel;       // 底部提示文本
@property (nonatomic, strong) UIButton *actionButton;        // 底部点击区域
@property (nonatomic, assign) BOOL isVideoAd;               // 是否为视频广告
@property (nonatomic, weak) id<BBTSplashDelegate> delegate;


// 更新跳过按钮倒计时
- (void)updateSkipButtonWithTime:(NSInteger)seconds;

// 设置图片广告内容
- (void)setupWithImageUrl:(NSString *)imageUrl 
               actionTip:(NSString *)actionTip
               source:(NSString *)source
               sourceLogo:(NSString *)sourceLogo;

// 设置视频广告内容
- (void)setupWithVideoUrl:(NSString *)videoUrl
               actionTip:(NSString *)actionTip;

// 清理视频资源
- (void)cleanupVideoResources;

@end
