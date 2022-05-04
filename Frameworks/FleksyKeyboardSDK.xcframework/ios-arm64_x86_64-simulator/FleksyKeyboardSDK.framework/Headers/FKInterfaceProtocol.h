//
//  FKInterface.h
//  FleksyKeyboardSDK
//
//  Created by Antonio J Pallares on 17/1/22.
//  Copyright © 2022 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FKInterfaceDelegate.h"
@import FleksyEngine;

NS_ASSUME_NONNULL_BEGIN

@protocol FKInterfaceProtocol <NSObject>

- (FLKeyboardID)keyboardID;
- (void)setKeyboardID:(FLKeyboardID)keyboardID;

/// Use this method to change the delegate of the Interface.
/// @param interfaceDelegate The new delagate for the Interface.
///
/// By default, your @c FKKeyboardViewController subclass is the delegate (note that @c FKKeyboardViewController implements the @c FKInterfaceDelegate protocol).
- (void)setInterfaceDelegate:(NSObject<FKInterfaceDelegate> *)interfaceDelegate;

- (void) insertText:(NSString*) text;
- (void) replaceText:(NSString*) text inRange:(NSRange) range;
- (void) replaceAllTextWith:(NSString*) text;
- (void) deleteBackward;
- (void) deleteBackwardWord;

- (void) insertWordPrediction:(NSString*) prediction
                     withType:(FLWordPredictionType) type;

- (void) updateFlaggedWordsFile:(NSString*)filePath
                    forLanguage:(NSString*) language;

// This method is not going to be maintained, move to loadCollectionActions
- (void) enableCollectionActions:(BOOL) value
                  collectionText:(BOOL) text __deprecated;

- (void) loadCollectionActions:(CaptureConfiguration*) capture;
- (void) enableEncryptionWithKey:(NSString*) key;

- (void) subscribeEventBus:(NSArray*) arrayEvents;

- (UIView*) getPanelCustomTopbarView;

- (BOOL) reloadTheme:(NSDictionary*) theme;

- (BOOL) changeLanguageTo:(NSString *)languageCode layout:(NSString*) layout;

- (void) updateFullAccess:(BOOL) fullaccess;
- (void) updateKeyboardInsets:(UIEdgeInsets) insets;

- (void) addCustomActions:(NSDictionary*) dict;

// User Dictionary management
- (void) addWordUserDictionary:(NSString*) word;
- (NSArray*) listWordUserDictionary;
- (void) removeWordUserDictionary:(NSString*) word;
- (void) removeAllWordsUserDictionary;

// AutoLearn: delete the current learnings
- (void) deleteAutolearnDictionary;

// Reload Settings
- (void) reloadSettings;
// Reload Configuration to Emojis
- (void) reloadConfiguration:(EmojiConfiguration*) configuration;
// Reload Dynamic Configuration
- (void) reloadDynamicConfiguration:(KeyboardDynamicConfiguration*) configuration;

// Add extra Data to collected data
//
- (void) addCustomCollectedData:(NSDictionary*) dict;

// Data Collector Management
// This is intended to be used for Testing purposes
// You cannot relay on this method to get the data, as data depends on
// different process that could provoke inconsistency if you call this.
- (void) flushCollectedData __deprecated;

// DEBUG: This triggers all events at the end of a session
// This is intended to be used for Testing purposes and
// this will be the new method instead of flushCollectedData
- (void) debugFlushRestartTypingSession;

// DEUBG: This will help debugging the system to inject points
// that will be translated to keys, actions
- (void) debugSendPoint:(CGPoint)point endPoint:(CGPoint) endPoint diff:(NSTimeInterval)time;
- (void) debugSendPrediction:(CGPoint)point endPoint:(CGPoint) endPoint diff:(NSTimeInterval)time;

// KeyboardApp
- (NSArray*) availableKeyboardApp;
- (BOOL) registerKeyboardApp:(FKAppsObject*) keyboardApp;
- (void) unregisterKeyboardApp:(FKAppsObject*) keyboardApp;
- (void) displayKeyboardApp:(NSString*) keyboardAppName withTerm:(NSString*) term;
- (void) closeKeyboardApp;

@end

NS_ASSUME_NONNULL_END
