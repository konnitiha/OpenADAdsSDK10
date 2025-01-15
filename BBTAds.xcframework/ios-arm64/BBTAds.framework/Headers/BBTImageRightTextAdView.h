#import <UIKit/UIKit.h>
#import "BBTFeedManager.h"
#import "BBTAdViewProtocol.h"

@interface BBTImageRightTextAdView : UIView <BBTNativeAdRenderProtocol>

@property (nonatomic, weak) id<BBTAdViewDelegate> delegate;
@property (nonatomic, strong) UIImageView *adImageView;    // 广告图片
@property (nonatomic, strong) UILabel *titleLabel;         // 标题
@property (nonatomic, strong) UILabel *priceLabel;         // 价格标签
@property (nonatomic, strong) UILabel *promotionLabel;     // 促销信息
@property (nonatomic, strong) UIButton *closeButton;       // 关闭按钮
@property (nonatomic, strong) UILabel *adLabel;            // 广告标识
@property (nonatomic, strong) UIButton *actionButton;      // 行动按钮
@property (nonatomic, strong) UIImageView *logoImageView;  // logo图片

- (void)setupWithAdsData:(BBTFeedAdData *)adData;

@end 