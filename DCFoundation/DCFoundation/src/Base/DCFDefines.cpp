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

static std::thread::id __mainThread;

DCF_LIBRARY_INITIALIZER void getMainThread() {
    static std::once_flag flag;
    std::call_once( flag, [](){
        __mainThread = std::this_thread::get_id();
    } );
}

DCF_NAMESPACE_END

std::thread::id std::main_thread_id() {
    DCF::getMainThread();
    
    return DCF::__mainThread;
}

bool std::this_thread::is_main_thread() {
    return ( std::this_thread::get_id() == std::main_thread_id() );
}

