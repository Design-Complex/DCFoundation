//
//  DCFDefines.h
//  DCFoundation
//
//  Created by Rob Dotson on 4/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFDefines_
#define _DCFDefines_

#include <cstddef>
#include <cstdint>
#include <limits>

/*! \file */

/** @namespace DCF
 @brief All DCFoundation types, classes, functions and variables are declared within this namespace.
 */
namespace DCF {}

    ///
extern const char *    kPlatformCurrentKey;

    //#define DCF_USE_STD_STRING 1

#define DCFGenericStringType            std::shared_ptr<std::string>

#endif // _DCFDefines_
