//
//  DCFDarwinPlatform.cpp
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#include "DCFDarwinPlatform.h"
#include "DCFConcurrency.h"
#include "DCFHost.h"
#include "DCFString.h"
#include <sys/sysctl.h>

static const char * kSysCTLActiveCPUKey     = "hw.activecpu";

size_t DCFHost::numberOfCores() const {
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

#pragma mark - DCFString

#if !defined( DCF_USE_STD_STRING )

DCFString::~String() {
            if( _storage )
                CFRelease( _storage );
}

DCFString * DCFString::init() {
    if( this->DCFObject::init() ) {
            // NULL String
    }
    
    return this;
}

DCFString * DCFString::initWithString( const DCFString * string ) {
    if( this->DCFObject::init() ) {
        _storage = CFRetain( string->_storage );
    }
    
    return this;
}

DCFString * DCFString::initWithCString( const char * string ) {
    if( this->DCFObject::init() ) {
        _storage = CFStringCreateWithCString( NULL, string, kCFStringEncodingASCII );
        if( !_storage )
            delete this;
    }
    
    return this;
}

DCFString * DCFString::initWithCStringNoCopy( const char * string ) {
        // TODO: I don't know that this is possible
    if( this->DCFObject::init() ) {
        _storage = CFStringCreateWithCStringNoCopy( NULL, string, kCFStringEncodingASCII, kCFAllocatorNull );
        if( !_storage )
            delete this;
    }
    
    return this;
}

DCFString * DCFString::initWithCStringOfLength( const char * string, size_t length ) {
    if( this->DCFObject::init() ) {
        _storage = DCFPlatformStringType( new std::string( string, length ) );
    }
    
    return this;
}

DCFString * DCFString::initWithBytes( const uint8_t * buffer, size_t length, Encoding encoding ) {
    if( this->DCFObject::init() ) {
        switch ( encoding ) {
            case kDCFStringUTF32Encoding:
            case kDCFStringUTF16Encoding:
            case kDCFStringUTF8Encoding:
                delete this;
                
                break;
            case kDCFStringASCIIEncoding:
            default:
                _storage = DCFPlatformStringType( new std::string( ( const char * )buffer, length ) );
        }
        
    }
    
    return this;
}

#endif // USE_STD_STRING