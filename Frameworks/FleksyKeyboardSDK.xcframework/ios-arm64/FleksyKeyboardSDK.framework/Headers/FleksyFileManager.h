//
//  FleksyFileManager.h
//  iFleksy2
//
//  Created by Vince Mansel on 6/13/14.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FleksyProtocols.h"

/**
 Manages file system operations. Tries to ensure that the container and the extension 
 aren't reading or writing at the same time.
 
 A few notes: 
 
 - The document directory in an extension is temporary. Only the shared container persists between processes
 - If full access isn't on, we can't write to the file system from the extension. This class ensures that we dont' do this while full access is off
 - If full access isn't on, we want to read the langauge pack from the main bundle, instead of trying to read from the shared container (we won't find anything)
   The file manager tries to abstract this away.

 Probably should be refactored, or even rethought from the ground up.
 */
@interface FleksyFileManager : NSObject <NSFilePresenter>

@property (nonatomic, strong) NSString *appGroup;
@property (nonatomic, readonly) BOOL canwriteToResource;
@property (nonatomic, readonly) NSURL *writeableURL;

+ (instancetype)sharedInstance;
- (NSString *)getWritableDirectory;
- (NSString *)pathForFilename:(NSString*) filename;
- (NSString *)pathForLanguage:(NSString *)lanId;
- (BOOL)languageHasBuiltinFile:(NSString *)languageID;
- (NSString*) folderPathToSharedResources;
- (NSString *)pathForNSPFolderForLanguage:(NSString *)languageCode;
- (NSString *)pathNameForNSPFolderForLanguage:(NSString *)languageCode;

/*
 *  Return the path of the folder for NSP - this is written in the shared container inside a folder
 *  We check if the folder exists, in case that nope, we create the directory.
 *  It returns a valid folder for adding all data of NSP there.
 */
- (NSString*) folderPathWritable;
- (NSString *)pathForDataStats;
- (NSString *)pathForMedicalDataStats;
- (NSString *)folderPathForEmojiImages;
- (NSError *)writeDictionary:(NSDictionary *)dictToWrite
                      toFile:(NSString *)dictFileName;
- (NSError *)writeToFilename:(NSString *)filename
                   withBlock:(void(^)(NSString *))writeBlock;
- (NSError *)writeToFilepath:(NSString *)filepath
                   withBlock:(void(^)(NSString *))writeBlock;
- (NSError *)writeToURL:(NSURL *)URL
              withBlock:(void(^)(NSURL *))writeBlock;
- (NSError *)deleteFilePath:(NSString *)filepath;
- (NSError *)deleteFileAtURL:(NSURL *)URL;
- (NSString *)getDefaultLanguagePackResourcePath;
- (NSError *)readAndModifyFile:(NSString *)fileName
                     withBlock:(void (^)(NSDictionary *))readAndModifyBlock;
- (NSError *)readFilename:(NSString *)filename
                withBlock:(void (^)(NSString *))readBlock;
- (NSError *)readFilePath:(NSString *)filepath
                withBlock:(void (^)(NSString *))readBlock;
+ (NSString *)pathForFileInBundle:(NSString *)filename;
- (id)readPlist:(NSString *)filename
      withError:(NSError *__autoreleasing*)error;

@end
