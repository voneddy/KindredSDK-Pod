//
//  FLJetFileReader.h
//  FleksyContainer
//
//  Created by Kosta Eleftheriou on 10/9/14.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Interface for reading jetfiles and extracting their properties.
 */
@interface FleksyJetFileReader : NSObject

// Convenience methods
+ (void)letterLayoutsForLanguagePack:(NSString *)aLanguagePack
                             success:(void (^)(NSString *defaultLayout, NSArray *availableLayouts))didFindLetterLayouts;
+ (NSString *)getJetFileVersionForResource:(NSString *)resourceFilePath;


- (instancetype)initWithLanguagePath:(NSString *)languagePath;
- (NSString *)defaultKeyboard;
- (NSArray<NSString *> *)availableLayouts;

@end
