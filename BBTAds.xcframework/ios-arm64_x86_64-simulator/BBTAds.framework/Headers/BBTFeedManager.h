//
//  BBTNativeManager.h
//  testPod
//
//  Created by AI on 2024/3/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BBTFeedAdData.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BBTNativeAdRenderProtocol;
@protocol BBTFeedDelegate;

@interface BBTFeedManager : NSObject

@property (nonatomic, copy) NSString *mediaId;
@property (nonatomic, assign) NSInteger adCount;
@property (nonatomic, weak) id<BBTFeedDelegate> delegate;
@property (nonatomic, strong) BBTFeedAdData *adData;

- (void)loadAdData;
- (UIView<BBTNativeAdRenderProtocol> *)createAdViewWithStyle:(BBTFeedAdStyle)style size:(CGSize)size;
- (void)registerAdForView:(UIView<BBTNativeAdRenderProtocol> *)view adData:(BBTFeedAdData *)adData;
- (void)unregisterAdData:(BBTFeedAdData *)adData;

@end

@protocol BBTNativeAdRenderProtocol <NSObject>

@required
- (void)setupWithAdsData:(BBTFeedAdData *)adData;

@end

@protocol BBTFeedDelegate <NSObject>

@optional
- (void)feedAdDidLoad:(NSArray *)ads;
- (void)feedAdDidFail:(NSError *)error;
- (void)feedAdDidClick;
- (void)feedAdDidVisible;
- (void)feedAdDidClose;
- (void)feedAdDidCloseOtherController;

@end

NS_ASSUME_NONNULL_END 
