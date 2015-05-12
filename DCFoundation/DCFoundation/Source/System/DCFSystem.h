//
//  DCFSystem.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#ifndef __DCFSystem__
#define __DCFSystem__

/*! \file */

#pragma mark - APPLE

#if !defined( __DARWIN__ )

#if defined( __APPLE__ ) && defined( __MACH__ )

#define __DARWIN__
#include <TargetConditionals.h>
#include <DCFoundation/DCFDarwinPlatform.h>

#endif // defined( __APPLE__ )
#endif // defined( __DARWIN__ )

#pragma mark - UNIX

#pragma mark - Windows

#if !defined( __WINDOWS__ )

#if defined( WIN32 ) || defined( _WIN32 ) || defined( __WIN32 ) || defined( __WIN32__ ) \
|| defined( WIN64 ) || defined( _WIN64 ) || defined( __WIN64 ) || defined( __WIN64__ ) \
|| defined( __MINGW32__ ) || defined( __MINGW64__ )

#define __WINDOWS__
#import <DCFoundation/DCFWindowsPlatform.h>

#endif // defined( WIN32 )...
#endif // defined( __WINDOWS__ )

#if !defined( __DCFPlatform__ )

#error "Unknown platform!"

#endif // Unknown Platform

#endif // __DCFSystem__
