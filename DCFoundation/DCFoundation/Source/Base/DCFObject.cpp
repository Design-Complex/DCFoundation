//
//  DCFObject.cpp
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#include "DCFObject.h"

#include <sstream>
#include <cxxabi.h>
#include <map>

DCF_NAMESPACE_BEGIN

#pragma mark Static Variables

using DCFTypeDictionary = std::map<const char *,std::string>;
static DCFMutex _typeLock;
static DCFTypeDictionary _types{};

#pragma mark Static Methods



#pragma mark Constructors

DCFObject::DCFObject() {
    
}

#pragma mark Destructor
DCFObject::~DCFObject() {
    
}

#pragma mark - Public Members

#pragma mark Accessor & Mutator Members

std::string DCFObject::description() const {
    return this->debugDescription();
}

std::string DCFObject::debugDescription() const {
    std::stringstream ss( std::ios_base::out );
    
    ss << "<";
    ss << this->className();
//    ss << "( " << typeid( *this ).name() << " )";
    ss << "@";
    ss << static_cast<const void *>( this );
    ss << ">";
    
    return ss.str();
}

std::vector<std::string> & DCFObject::classPath() const { // Just a stub
    std::vector<std::string> * s = new std::vector<std::string>;
    
    return *s;
}

const std::string & DCFObject::className() const {
    
    DCFMutexGuard g( _typeLock );
    
        /// Find this type id
    const char * type = DCF_THIS_TYPE.name();
    DCFTypeDictionary::iterator i = _types.find( type );
   
        // Found it! Return
    if( i != _types.end() )
        return i->second;
    
        // Couldn't find it, let's create one!
    {
        int status = -4;
        
        std::unique_ptr<char, decltype( std::free ) *> p{ abi::__cxa_demangle( type, nullptr, nullptr, &status ), std::free };
        
        switch ( status ) {
            case 0:
                _types[ type ] = &( *p );
                
                break;
            case -1:
                    throw std::bad_alloc();
                break;
            case -2:
                    throw std::invalid_argument( "The mangled name is not valid!" );
                break;
            case -3:
                throw std::invalid_argument( "One of the arguments is invalid!" );
                break;
            default:
                break;
        }
    }
    
    return _types[ type ];
}

DCF_NAMESPACE_END
