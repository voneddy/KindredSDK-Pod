//
//  InternalHeaders.h
//  FleksyKeyboardSDK
//
//  Created by Antonio Jesús Pallares Martín on 16/11/21.
//  Copyright © 2021 Thingthing. All rights reserved.
//

// These internal headers are needed for Swift code to be able to access their code.
// However, they should not be shipped in XCFrameworks to clients since they are
// supposed to be internal, i.e., not visible outside the scope of the framework.

// See https://stackoverflow.com/a/63175460 for orientation on how to remove internal
// headers from a framework.

#import "FleksyFileManager.h"
#import "FKInterfaceHelper+Internal.h"
#import "NSBundle+Fleksy.h"
#import "FleksySettingsManager.h"
#import "FleksyJetFileReader.h"
