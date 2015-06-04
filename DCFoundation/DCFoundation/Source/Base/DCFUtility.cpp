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

const char * DCFDemangleIdentifier( const char * mangled ) {
        // No input!
    if( mangled == nullptr || mangled == NULL )
        return "";
    
    {
        int     status  = -4;
        
        std::unique_ptr<char, decltype( std::free ) *> p{ abi::__cxa_demangle( mangled, nullptr, nullptr, &status ), std::free };
        
        switch ( status ) {
            case 0:
                return p.get();
                
                break;
            case -1: // Couldn't allocate
                throw std::bad_alloc();
                break;
            case -2: // Invalid mangled name
                throw std::invalid_argument( "The mangled name is not valid!" );
                break;
            case -3: // Invalid argment
                throw std::invalid_argument( "One of the arguments is invalid!" );
                break;
            default: // Hrm. Shouldn't have reached here.
                std::string s( "Reached impossible code: " );
                throw std::runtime_error( s.append( __PRETTY_FUNCTION__ ) );
                break;
        }
    }
    
        return mangled;
}

DCF_NAMESPACE_END