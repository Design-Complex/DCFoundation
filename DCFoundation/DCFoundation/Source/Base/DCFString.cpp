//
//  DCFString.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFString.h"

#if DCF_USE_STD_STRING

DCFString::String() {
    
}

DCFString::~String() {
//    if( _storage )
//        delete _storage;
}

DCFString * DCFString::init() {
    if( this->DCFObject::init() ) {
            // NULL String
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

const DCFHashCode DCFString::hash() const {
    return std::hash<decltype(this)>()( this );
}