//
//  DCFConcurrency.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 4/27/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFConcurrency.h"

#include <mutex>

DCF_NAMESPACE_BEGIN

DCF_LIBRARY_INITIALIZER DCFThreadID getMainThread() {
    static std::once_flag flag;
    static DCFThreadID __mainThread;
    std::call_once( flag, [](){
        __mainThread = currentThreadID();
    } );
    
    return __mainThread;
}

bool isMainThread() {
    return isMainThread( currentThreadID() );
}

bool isMainThread( const DCFThreadID threadID ) {
    return ( threadID == getMainThread() );
}

DCFThreadID currentThreadID() {
    return std::this_thread::get_id();
}

DCF_NAMESPACE_END