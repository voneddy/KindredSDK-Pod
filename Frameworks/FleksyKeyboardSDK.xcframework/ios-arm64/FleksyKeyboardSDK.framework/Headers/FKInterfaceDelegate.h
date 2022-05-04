//
//  FKInterfaceDelegate.h
//  FleksyKeyboardSDK
//
//  Created by Antonio J Pallares on 18/1/22.
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FKAppsGenericViewController;
@class FKAppsObject;
@protocol FKAppsGenericInteractionProtocol;

/// Methods to receive keyboard data collection and events.
@protocol FKInterfaceDelegate <NSObject>

@optional

- (void)eventBus:(NSString *)event payload:(NSDictionary *)dictPayload;

/// Implement this method to receive the data captured in form of string.
///
/// This method gets executed in a background thread.
/// @param data The data captured in form of string.
- (void)dataCollection:(NSString *)data;

/// Implement this method to receive the data captured in dictionary form.
///
/// This method gets executed in a background thread.
/// @param data The data captured in form of string.
- (void)dataCollectionFormatDict:(NSDictionary *)data;

/// Report Analytics is accumulative, which means that accumulates all statistics for you,
- (void)reportAnalytics:(NSDictionary *)data;

- (void)customMagicButton:(NSString *)element forAction:(int)action;

/// Report Layout changes
- (void)onLayoutChanges:(NSDictionary *)dictLayout;

- (void)updateKeyboardAppsTextDocumentProxy:(nullable id<UITextDocumentProxy>)documentProxy;

- (nullable FKAppsGenericViewController*) customKeyboadApp:(FKAppsObject*) object
                                     withDelegate:(id<FKAppsGenericInteractionProtocol>) delegate;

/// Implement this method if you want to get all
/// updates of the KeyboardProperties changes.
- (void)contextPropertiesChanged:(KeyboardProperties*)properties;

/// Do here anything you want at button press - "magnifier button"
- (void)triggerOpenApp;

@end

NS_ASSUME_NONNULL_END
