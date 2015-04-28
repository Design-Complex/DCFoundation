//
//  DCFConcurrency.h
//  DCFoundation
//
//  Created by Rob Dotson on 4/27/15.
//  Copyright (c) 2015 Rob Dotson, Design Complex. All rights reserved.
//

#ifndef __DCFConcurrency__
#define __DCFConcurrency__

#include <DCFoundation/DCFMacros.h>
#include <thread>
#include <future>

DCF_NAMESPACE_BEGIN

using DCFThreadID = std::thread::id;

DCF_EXPORT DCFThreadID getMainThread();

DCF_EXPORT bool isMainThread();
DCF_EXPORT bool isMainThread( const DCFThreadID threadID );

DCF_NAMESPACE_END

#endif // __DCFConcurrency__
