#import <UIKit/UIKit.h>
#import "BBTFeedManager.h"
#import "BBTAdViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface BBTMixedAdView : UIView <BBTNativeAdRenderProtocol>

@property (nonatomic, weak) id<BBTAdViewDelegate> delegate;
@property (nonatomic, strong) UILabel *titleLabel;          // 标题
@property (nonatomic, strong) UIImageView *mainImageView;   // 主图片
@property (nonatomic, strong) UILabel *descLabel;           // 底部描述文字
@property (nonatomic, strong) UIButton *closeButton;        // 关闭按钮
@property (nonatomic, strong) UILabel *adLabel;             // 广告标识
@property (nonatomic, strong) UIImageView *logoImageView;   // logo图片

- (void)setupWithAdsData:(BBTFeedAdData *)adData;

@end

NS_ASSUME_NONNULL_END 
