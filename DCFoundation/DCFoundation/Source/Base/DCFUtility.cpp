//
//  DCFUtility.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 5/5/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include <cxxabi.h>

#include "DCFUtility.h"

DCF_NAMESPACE_BEGIN

void DCFDemangleIdentifier( const char * mangled, char * unmangled ) {
    if( mangled == nullptr || mangled == NULL )
        return ;;
    
    int status = -4;
    std::unique_ptr<char, decltype( std::free ) *> p{ abi::__cxa_demangle( mangled, nullptr, nullptr, &status ), std::free };
    
    
    
}

DCF_NAMESPACE_END