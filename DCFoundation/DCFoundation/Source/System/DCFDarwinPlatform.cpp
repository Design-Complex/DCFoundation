//
//  DCFDarwinPlatform.cpp
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#include "DCFDarwinPlatform.h"
#include "DCFConcurrency.h"
#include <sys/sysctl.h>

DCFSingletonDefine( DCFDarwinPlatform );

static const char * kSysCTLActiveCPUKey     = "hw.activecpu";

DCFDarwinPlatform::DarwinPlatform() {}
DCFDarwinPlatform::~DarwinPlatform() {}

size_t DCFDarwinPlatform::numberOfCores() const {
    static size_t _numCores = 0;
    static std::once_flag _numCoresOnce;
    std::call_once( _numCoresOnce, [](){
        int count   = 0;
        size_t len  = sizeof( count );
        sysctlbyname( kSysCTLActiveCPUKey, &count, &len, NULL, 0 );
        
        _numCores = ( count > 0 ) ? ( size_t )count : 0;
    } );

    return _numCores;
}