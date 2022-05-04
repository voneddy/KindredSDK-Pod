//
//  FKInterfaceInputViewController.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 03/07/2019.
//  Copyright © 2019 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FKInputView.h"
#import "KeyboardConfiguration.h"
#import "KeyboardProperties.h"
#import "FKInterfaceProtocol.h"
#import "FKInterfaceDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Data Collection protocol to implement in order to receive calls
 *  when we upload the data.
 *  Create an object extending this one and pass it via viewWillDissappearWithDataCollection(...)
 */
@protocol FKDataCollection <NSObject>

- (void) dataCollection:(NSString*) data;
- (void) dataCollectionFormatDict:(NSDictionary*) data;

@end

/**
 *  Interface to be implemented to receive any of these calls as a protocol
 */
@protocol FKInterfaceInputViewControllerDelegate <NSObject, FKInterfaceDelegate>

- (void) addKeyboardViewController:(UIViewController *) currentKeyboardVC;
- (void) addDisplayedViewController:(UIViewController<FleksyThemeableUI> *) displayVC;
- (void) addExtensionsViewController:(UIViewController*) extensionsVC;

- (void) dismissKeyboardButton;
- (void) changeKeyboardButton;

@end

/**
 * Main object to interact which owns the keyboard SDK
 */
@interface FKInterfaceInputViewController : NSObject<FKInterfaceProtocol>

@property (nonatomic) FLKeyboardID keyboardID;

- (instancetype) initWith:(UIView*)inputView
                     view:(UIView*) view
        textDocumentProxy:(NSObject<UITextDocumentProxy>*) textDocumentProxy
          trailCollection:(UITraitCollection*) traitCollection
                 protocol:(NSObject<FKInterfaceInputViewControllerDelegate>*) protocol;

- (instancetype) initWith:(UIView*)inputView
        textDocumentProxy:(NSObject<UITextDocumentProxy>*) textDocumentProxy
          trailCollection:(UITraitCollection*) traitCollection
                 protocol:(NSObject<FKInterfaceInputViewControllerDelegate>*) protocol
            configuration:(KeyboardConfiguration*) config;

- (instancetype) initWith:(UIView*)inputView
        textDocumentProxy:(NSObject<UITextDocumentProxy>*) textDocumentProxy
          trailCollection:(UITraitCollection*) traitCollection
                 protocol:(NSObject<FKInterfaceInputViewControllerDelegate>*) protocol
                   output:(nullable NSObject<FKDataCollection>*) output
            configuration:(KeyboardConfiguration*) config;

- (void) viewWillAppear;
- (void) viewDidAppear;
- (void) viewWillDisappear;

- (void)textWillChange:(nullable id<UITextInput>)textInput;
- (void)textDidChange:(nullable id<UITextInput>)textInput;

- (void)selectionWillChange:(nullable id<UITextInput>)textInput;
- (void)selectionDidChange:(nullable id<UITextInput>)textInput;

@end

NS_ASSUME_NONNULL_END
