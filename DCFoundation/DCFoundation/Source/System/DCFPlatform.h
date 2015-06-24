//
//  DCFPlatform.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#ifndef __DCFPlatform__
#define __DCFPlatform__

#include <DCFoundation/DCFMacros.h>
#include <DCFoundation/DCFDefines.h>

#pragma mark - APPLE

#if !defined( __DARWIN__ )
#if defined( __APPLE__ ) && defined( __MACH__ )

#define __DARWIN__

#endif // defined( __APPLE__ )
#endif // defined( __DARWIN__ )

#pragma mark - UNIX

#pragma mark - Windows

#if !defined( __WINDOWS__ )
#if defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32 ) || defined( __WIN32__ ) \
|| defined( WIN64 ) || defined( _WIN64 ) || defined( __WIN64 ) || defined( __WIN64__ ) \
|| defined( __MINGW32__ ) || defined( __MINGW64__ )

#define __WINDOWS__

#endif // defined( WIN32 )...
#endif // defined( __WINDOWS__ )

#if defined( __DARWIN__ )

//#define DCF_USE_COREFOUNDATION 1
//#undef DCF_USE_STD_STRING

#include <DCFoundation/DCFDarwinPlatform.h>

#elif defined( __WINDOWS__ )

#include <DCFoundation/DCFWindowsPlatform.h>

#elif defined( __LINUX__ )

#include <DCFoundation/DCFLinuxPlatform.h>

#else

#warning "Unknown Platform"

#endif // Platforms

#endif // __DCFPlatform__
