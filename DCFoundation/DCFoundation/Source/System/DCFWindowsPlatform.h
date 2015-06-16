//
//  DCFWindowsPlatform.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#ifndef __DCFWindowsPlatform__
#define __DCFWindowsPlatform__

/*! \file */

#pragma mark - Includes

#define __WINDOWS__
#include <DCFoundation/DCFPlatform.h>

#pragma mark - Macro Definitions

/*! @def BUILDING_DCFOUNDATION
 @brief This macro should be defined when building the DCFoundation library. It's only use is here, when determining the visibility of symbols for Windows.
 */
#if defined( BUILDING_DCFOUNDATION )
#define DCF_VISIBLE __declspec( dllexport )
#else
#define DCF_VISIBLE __declspec( dllimport )
#endif // BUILDING_DCFOUNDATION

#undef DCF_EXPORT
#define DCF_EXPORT DCF_EXTERN DCF_VISIBLE

#endif // __DCFWindowsPlatform__
