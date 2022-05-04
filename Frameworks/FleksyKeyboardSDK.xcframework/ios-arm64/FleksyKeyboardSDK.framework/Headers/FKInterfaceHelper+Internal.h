//
//  FKInterfaceHelper+Internal.h
//  FleksyKeyboardSDK
//
//  Created by Antonio Jesús Pallares Martín on 17/11/21.
//  Copyright © 2021 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FKInterfaceHelper.h"

@interface FKInterfaceHelper (Internal)

- (NSURL * _Nullable)getManifestURL;

/// Use this property to know whether the list of available languages are loaded. If not, use \c loadAvailableLanguagesWithCompletion: to load them.
/// Also, downloading any language forces the load of the available languages, in case they are not yet loaded.
@property (assign, nonatomic, readonly) BOOL areAvailableLanguagesLoaded;

/// Returns the array of available languages to download. This array includes the already downloaded languages. Each language is a \c NSString [language ISO 639-1]-[Country ISO 3166-alpha2].
///
/// This returns an empty array if languages have not been yet loaded (see \c areAvailableLanguagesLoaded ).
- (NSArray<NSString *> * _Nonnull)availableLanguages;

/// Downloads the list of languages available to download as well as some internal metadata related to each language.
/// @param completion A block that executes when the download finishes. A nil \c NSError means that the download completed successfully.
/// Calling this method when the available languages have already been download executes the \c completion block synchronously.
///
/// After a successful load of the available languages, they can be accessed with \c availableLanguages .
- (void)loadAvailableLanguagesWithCompletion:(void (^ _Nullable) (NSError * _Nullable))completion;

/// Downloads the given language.
/// @param language \c NSString with the value of the language:  [language ISO 639-1]-[Country ISO 3166-alpha2].
/// @param installLanguage Indicates whether the language should be installed right after it is downloaded.
/// @param detailedUpdateHandler A progress-reporting block that reports the downloaded bytes \c bytesCurrent as well as the total bytes to download \c bytesTotal .
/// @param completion A block that executes when the language finishes downloading. A \c nil \c NSError means that the language downloaded successfully.
///
/// This method downloads the list of available languages initially, in case this list has not been downloaded yet.
- (void)downloadLanguage:(NSString *)language installLanguage:(BOOL)installLanguage detailedProgress:(void (^ _Nullable)(float bytesCurrent, float bytesTotal))detailedUpdateHandler completion:(void (^ _Nullable)(NSError * _Nullable))completion;

@end
