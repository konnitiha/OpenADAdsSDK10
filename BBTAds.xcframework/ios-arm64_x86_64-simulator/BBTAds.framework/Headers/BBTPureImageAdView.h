#import <UIKit/UIKit.h>
#import "BBTFeedManager.h"
#import "BBTAdViewProtocol.h"

@interface BBTPureImageAdView : UIView <BBTNativeAdRenderProtocol>

@property (nonatomic, weak) id<BBTAdViewDelegate> delegate;
@property (nonatomic, strong) UIImageView *adImageView;
@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) UILabel *adLabel;
@property (nonatomic, strong) UIImageView *logoImageView;

- (void)setupWithAdsData:(BBTFeedAdData *)adData;

@end 