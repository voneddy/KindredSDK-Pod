//
//  FKKeyboardViewController.h
//  FleksyKeyboardSDK
//
//  Created by Antonio J Pallares on 17/1/22.
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KeyboardConfiguration.h"
#import "KeyboardProperties.h"
#import "FKInterfaceProtocol.h"
#import "FKInterfaceDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class FKAppsGenericViewController;
@class FKAppsObject;
@protocol FKAppsGenericInteractionProtocol;

@interface FKKeyboardViewController : UIInputViewController<FKInterfaceDelegate>

@property (strong, nonatomic, readonly) id<FKInterfaceProtocol> interface;

#pragma mark - Required methods to override

/// Returns the configuration for the keyboard.
///
/// This method must be overriden by subclasses to return a configuration containing, in particular, a valid @c LicenseConfiguration  object.
/// Do not call super's implementation. Doing that will throw an exception.
- (nonnull KeyboardConfiguration *)createConfiguration;

@end

NS_ASSUME_NONNULL_END
