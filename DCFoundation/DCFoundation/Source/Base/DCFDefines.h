//
//  DCFDefines.h
//  DCFoundation
//
//  Created by Rob Dotson on 4/16/15.
//  Copyright (c) 2015 Rob Dotson, Design Complex. All rights reserved.
//

#ifndef _DCFDefines_
#define _DCFDefines_

#include <DCFoundation/DCFMacros.h>
#include <thread>
#include <future>

DCF_NAMESPACE_BEGIN

DCF_EXPORT std::thread::id getMainThread();

DCF_EXPORT bool isMainThread();
DCF_EXPORT bool isMainThread( const std::thread::id threadID );

DCF_NAMESPACE_END

#endif // _DCFDefines_
