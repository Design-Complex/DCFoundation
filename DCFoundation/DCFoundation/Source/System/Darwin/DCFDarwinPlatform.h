//
//  DCFDarwinPlatform.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#ifndef __DCFDarwinPlatform__
#define __DCFDarwinPlatform__

/*! \file */

#define __DARWIN__

#pragma mark Includes

#include <Availability.h>
#include <AvailabilityMacros.h>
#include <TargetConditionals.h>
#include <string>

#pragma mark Concrete Type Definitions

#if defined( USE_COREFOUNDATION )

#include <CoreFoundation/CFString.h>

#undef DCFPlatformStringType
#define DCFPlatformStringType CFStringRef

#endif // USE_COREFOUNDATION

#endif // __DCFDarwinPlatform__
