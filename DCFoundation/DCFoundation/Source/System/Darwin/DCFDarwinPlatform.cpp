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
#include <CoreFoundation/CFString.h>
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

#if defined( DCF_USE_COREFOUNDATION )

const DCFStringEncoding kDCFStringEncodingMacRoman          = kCFStringEncodingMacRoman;
const DCFStringEncoding kDCFStringEncodingWindowsLatin1     = kCFStringEncodingWindowsLatin1;
const DCFStringEncoding kDCFStringEncodingISOLatin1         = kCFStringEncodingISOLatin1;
const DCFStringEncoding kDCFStringEncodingNextStepLatin     = kCFStringEncodingNextStepLatin;
const DCFStringEncoding kDCFStringEncodingASCII             = kCFStringEncodingASCII;
const DCFStringEncoding kDCFStringEncodingUnicode           = kCFStringEncodingUnicode;
const DCFStringEncoding kDCFStringEncodingUTF8              = kCFStringEncodingUTF8;
const DCFStringEncoding kDCFStringEncodingNonLossyASCII     = kCFStringEncodingNonLossyASCII;
const DCFStringEncoding kDCFStringEncodingUTF16             = kCFStringEncodingUTF16;
const DCFStringEncoding kDCFStringEncodingUTF16BE           = kCFStringEncodingUTF16BE;
const DCFStringEncoding kDCFStringEncodingUTF16LE           = kCFStringEncodingUTF16LE;
const DCFStringEncoding kDCFStringEncodingUTF32             = kCFStringEncodingUTF32;
const DCFStringEncoding kDCFStringEncodingUTF32BE           = kCFStringEncodingUTF32BE;
const DCFStringEncoding kDCFStringEncodingUTF32LE           = kCFStringEncodingUTF32LE;

DCFString::String() {
    this->init();
}

DCFString::~String() {
            if( _storage )
                CFRelease( _storage );
}

DCFString * DCFString::init() {
    if( this->DCFObject::init() ) {
        _storage = CFSTR("");
    }
    
    return this;
}

DCFString * DCFString::initWithString( const DCFString * string ) {
    if( this->DCFObject::init() ) {
        _storage = ( CFStringRef )CFRetain( string->_storage );
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

DCFString * DCFString::initWithBytes( const uint8_t * buffer, size_t length, DCFStringEncoding encoding ) {
    if( this->DCFObject::init() ) {        
        _storage = CFStringCreateWithBytes( NULL, buffer, ( CFIndex )length, encoding, false );
        if( !_storage )
            delete this;
    }
    
    return this;
}

#pragma mark - DCFHashable

const DCFHashCode DCFString::hash() const {
    return ( DCFHashCode )CFHash( _storage );
}

#endif // USE_STD_STRING
