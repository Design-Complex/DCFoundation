//
//  DCFConcurrency.h
//  DCFoundation
//
//  Created by Rob Dotson on 4/27/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef __DCFConcurrency__
#define __DCFConcurrency__

#include <DCFoundation/DCFLockable.h>

#include <thread>
#include <future>

DCF_NAMESPACE_BEGIN

    /// The unique identifier of a particular thread.
using DCFThreadID = std::thread::id;

    /// The unique identifier of the main (first) thread.
DCF_EXPORT DCFThreadID getMainThread();

    /// A function to determine if the current thread is the main (first) thread.
DCF_EXPORT bool isMainThread();

    /// A function to determine if a particular thread is the main (first) thread.
    /// @param threadID A valid DCFThreadID. Passing an empty value is undefined.
    /// @return A bool value specifing if the passed DCFThreadID is equal to the main (first)
    /// thread's DCFThreadID.
DCF_EXPORT bool isMainThread( const DCFThreadID threadID );

    /// A function to determine the current thread's identifier.
DCF_EXPORT DCFThreadID currentThreadID();

DCF_NAMESPACE_END

#endif // __DCFConcurrency__
