//
//  DCFString.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFString.h"

#if DCF_USE_STD_STRING

const DCFStringEncoding kDCFStringEncodingMacRoman          = 0;
const DCFStringEncoding kDCFStringEncodingWindowsLatin1     = 1;
const DCFStringEncoding kDCFStringEncodingISOLatin1         = 2;
const DCFStringEncoding kDCFStringEncodingNextStepLatin     = 3;
const DCFStringEncoding kDCFStringEncodingASCII             = 4;
const DCFStringEncoding kDCFStringEncodingUnicode           = 5;
const DCFStringEncoding kDCFStringEncodingUTF8              = 6;
const DCFStringEncoding kDCFStringEncodingNonLossyASCII     = 7;
const DCFStringEncoding kDCFStringEncodingUTF16             = 8;
const DCFStringEncoding kDCFStringEncodingUTF16BE           = 9;
const DCFStringEncoding kDCFStringEncodingUTF16LE           = 10;
const DCFStringEncoding kDCFStringEncodingUTF32             = 11;
const DCFStringEncoding kDCFStringEncodingUTF32BE           = 12;
const DCFStringEncoding kDCFStringEncodingUTF32LE           = 13;

DCFString::String() : _storage( /* default */ ) {
    this->init();
}

DCFString::~String() {
//    if( _storage )
//        delete _storage;
}

DCFString * DCFString::init() {
    if( this->DCFObject::init() ) {
        _storage.reset( new std::string( "" ) );
    }
    
    return this;
}

DCFString * DCFString::initWithString( const DCFString * string ) {
    if( this->DCFObject::init() ) {
        _storage = DCFPlatformStringType( string->_storage );
    }
    
    return this;
}

DCFString * DCFString::initWithCString( const char * string ) {
    if( this->DCFObject::init() ) {
        _storage = DCFPlatformStringType( new std::string( string ) );
    }
    
    return this;
}

DCFString * DCFString::initWithCStringNoCopy( const char * string ) {
        // TODO: I don't know that this is possible
    if( this->DCFObject::init() ) {
        _storage = DCFPlatformStringType( new std::string( string ) );
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
            // TODO: Fill me in!
        
                        _storage = DCFPlatformStringType( new std::string( ( const char * )buffer, length ) );

    }
    
    return this;
}

const DCFHashCode DCFString::hash() const {
    auto str = ( _storage ) ? _storage.get() : nullptr;
    
    
    return std::hash<decltype(str)>()( this );
}

#endif // USE_STD_STRING

DCFString * DCFString::withString( const DCFString * string ) {
    DCFString * output = new DCFString();
    
    output->initWithString( string );
    
    return output;
}

DCFString * DCFString::withCString( const char * cstring ) {
    DCFString * output = new DCFString();
    
    output->initWithCString( cstring );
    
    return output;
}

DCFString * DCFString::withCStringNoCopy( const char * cstring ) {
    DCFString * output = new DCFString();
    
    output->initWithCStringNoCopy( cstring );
    
    return output;
}

DCFString * DCFString::withCStringOfLength( const char * cstring, size_t length ) {
    DCFString * output = new DCFString();
    
    output->initWithCStringOfLength( cstring, length );
    
    return output;
}

DCFString * DCFString::withBytes( const uint8_t * buffer, size_t length, DCFStringEncoding encoding ) {
    DCFString * output = new DCFString();
    
    output->initWithBytes( buffer, length, encoding );
    
    return output;
}

