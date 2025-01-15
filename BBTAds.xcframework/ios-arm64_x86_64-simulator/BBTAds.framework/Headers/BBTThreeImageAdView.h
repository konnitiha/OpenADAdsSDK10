#import <UIKit/UIKit.h>
#import "BBTFeedManager.h"
#import "BBTAdViewProtocol.h"

@interface BBTThreeImageAdView : UIView <BBTNativeAdRenderProtocol>

@property (nonatomic, weak) id<BBTAdViewDelegate> delegate;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIView *imageContainer;
@property (nonatomic, strong) NSMutableArray<UIImageView *> *imageViews;
@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) UILabel *sourceLabel;
@property (nonatomic, strong) UIImageView *logoImageView;

- (void)setupWithAdsData:(BBTFeedAdData *)adData;

@end 