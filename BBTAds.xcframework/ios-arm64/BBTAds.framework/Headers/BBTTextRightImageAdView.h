#import <UIKit/UIKit.h>
#import "BBTFeedManager.h"
#import "BBTAdViewProtocol.h"

@interface BBTTextRightImageAdView : UIView <BBTNativeAdRenderProtocol>

@property (nonatomic, weak) id<BBTAdViewDelegate> delegate;
@property (nonatomic, strong) UIImageView *adImageView;    // 广告图片
@property (nonatomic, strong) UILabel *titleLabel;         // 标题
@property (nonatomic, strong) UIButton *closeButton;       // 关闭按钮
@property (nonatomic, strong) UILabel *adLabel;            // 广告标识
@property (nonatomic, strong) UILabel *descLabel;          // 描述文本
@property (nonatomic, strong) UIImageView *logoImageView;  // logo图片

- (void)setupWithAdsData:(BBTFeedAdData *)adData;

@end 