//
//  DCFDefines.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 4/16/15.
//  Copyright (c) 2015 Rob Dotson, Design Complex. All rights reserved.
//

#include "DCFDefines.h"
#include <mutex>

DCF_NAMESPACE_BEGIN

DCF_LIBRARY_INITIALIZER std::thread::id getMainThread() {
    static std::once_flag flag;
    static std::thread::id __mainThread;
    std::call_once( flag, [](){
        __mainThread = std::this_thread::get_id();
    } );
    
    return __mainThread;
}

bool isMainThread() {
    return isMainThread( std::this_thread::get_id() );
}
                  
bool isMainThread( const std::thread::id threadID ) {
    return ( threadID == getMainThread() );
}

DCF_NAMESPACE_END
