//
//  FleksyEngineUIUniqueIdentifiable.h
//  FleksyiOS
//
//  Created by Ben Pious on 3/4/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyiOS_FleksyEngineUIUniqueIdentifiable_h
#define FleksyiOS_FleksyEngineUIUniqueIdentifiable_h

#if __has_feature(modules)
@import FleksyEngine;
#else
#import "FleksyEngine/FLEnums.h"
#endif


/**
 A layout object from the engine, which has a uniqueID.
 */
@protocol FleksyEngineUIUniqueIdentifiable <NSObject>

@property (nonatomic) int uniqueID;
@property (nonatomic) FLButtonType buttonType;

@end

#endif
