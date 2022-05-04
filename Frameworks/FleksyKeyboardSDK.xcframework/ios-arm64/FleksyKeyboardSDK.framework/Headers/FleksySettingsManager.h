//
//  FleksySettingsManager.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 6/11/14.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FleksyProtocols.h"

/**
 Singleton wrapping NSUserDefaults.
 
 Emits FLEKSY_SETTINGS_DidChangeNotification when settings change.
 */
@interface FleksySettingsManager : NSObject

@property (nonatomic, readonly, strong) NSString *appGroup;

- (instancetype)init __attribute__((unavailable("Use sharedSettingsManager to get the singleton")));
+ (instancetype)sharedSettingsManager;
/**
 Sets the initial settings
 */
- (void)loadSettings;
- (void)loadSettings:(NSArray*) settings;
- (void)loadLanguage;
/**
 Save a setting. For the list of settings see FleksyDefines.h.
 @param settingName setting to save
 @param value the new setting value
 */
- (void)saveSetting:(NSString*)settingName
              value:(id)value;
/**
 get a setting from NSUserDefaults. For the list of settings see FleksyDefines.h.
 @returns the setting
 */
- (id)getSetting:(NSString *)settingName;
- (void)removeFontSetting;
- (BOOL)hasAskedPermissionForNotifications;
- (NSDictionary *)writeAppropriateSharedContainerUserDefaultsToExtensionDefaults;

#pragma mark - fast settings access
- (NSString *)currentLanguage;
- (NSString *)currentTheme;
- (NSString *)getBundledLanguage;
- (NSString *)currentLetterLayout;
- (NSArray *)purchases;

//cloud synch
- (void)propagateCloudSettingsToUserDefaults;
- (void)synchronizeWithCloud;
- (BOOL)cloudIsAheadOfLocalSettings;
- (void)setLastCloudUpdateDate;

// subscripting
- (id)objectForKeyedSubscript:(NSString *)idx;
- (void)setObject:(id)obj
forKeyedSubscript:(NSString *)idx;

- (void)executeOnce:(void (^)(void))block
             forKey:(NSString *)key;

@end
