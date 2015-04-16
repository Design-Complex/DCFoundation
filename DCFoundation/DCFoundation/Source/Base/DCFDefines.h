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

namespace std {
    std::thread::id main_thread_id();
    
    namespace this_thread {
        bool is_main_thread();
    }
}

#endif // _DCFDefines_
