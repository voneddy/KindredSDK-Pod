//
//  FKInterfaceHelper.h
//  FleksyHelperSDK
//
//  Created by Xevi Farrarons on 1/7/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FKInterfaceHelper : NSObject

/// Downloads the given language.
/// @param language \c NSString with the value of the language:  [language ISO 639-1]-[Country ISO 3166-alpha2].
/// @param updateHandler A progress-reporting block.
/// @param completion A block that executes when the language finishes downloading. A \c nil \c NSError means that the language downloaded successfully.
///
/// This method downloads the list of available languages initially, in case this list has not been downloaded yet.
- (void) downloadLanguage:(NSString*) language progress:(void (^)(float progress))updateHandler completion:(void (^)(NSError * _Nullable))completion;

/**
 Remove the language Installed
 */
- (void) removeLanguage:(NSString*) language;

@end

NS_ASSUME_NONNULL_END
