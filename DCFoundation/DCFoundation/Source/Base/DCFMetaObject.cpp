//
//  DCFMetaObject.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFMetaObject.h"
#include "DCFConcurrency.h"

#include <map>
#include <sstream>
#include <cxxabi.h>

DCF_NAMESPACE_BEGIN

using DCFTypeDictionary = std::map<const char *,std::string>;
static DCFMutex * _typeLock;
static DCFTypeDictionary * _types;

DCF_LIBRARY_INITIALIZER void DCFInitMetaObject();

DCF_LIBRARY_INITIALIZER void DCFInitMetaObject() {
    static std::once_flag __initMetaObject;
    std::call_once( __initMetaObject, [](){
        _types      = new DCFTypeDictionary{};
        _typeLock   = new DCFMutex;
    } );
}

DCFDefineAbstractDestructor( MetaObject );

std::string DCFMetaObject::description() const {
    return this->debugDescription();
}

std::string DCFMetaObject::debugDescription() const {
    std::stringstream ss( std::ios_base::out );
    
    ss << "<";
    ss << this->className();
        //    ss << "( " << typeid( *this ).name() << " )";
    ss << "@";
//    ss << static_cast<void const *>( this );
    ss << this;
    ss << ">";
    
    return ss.str();
}

std::vector<std::string> & DCFMetaObject::classPath() const { // Just a stub
    std::vector<std::string> * s = new std::vector<std::string>;
    
    return *s;
}

const std::string & DCFMetaObject::className() const {
    DCFInitMetaObject(); // Just in case
    
    DCFMutexGuard g( *_typeLock );
    
        /// Find this type id
    const char * type = DCF_THIS_TYPE.name();
    DCFTypeDictionary &dict = *_types;
    DCFTypeDictionary::iterator i = dict.find( type );
    
        // Found it! Return
    if( i != dict.end() )
        return i->second;
    
        // Couldn't find it, let's create one!
    {
        int status = -4;
        
        std::unique_ptr<char, decltype( std::free ) *> p{ abi::__cxa_demangle( type, nullptr, nullptr, &status ), std::free };
        
        switch ( status ) {
            case 0:
                dict[ type ] = &( *p );
                
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
    
    return dict[ type ];
}

bool DCFMetaObject::operator ==( const DCFMetaObject & rhs ) const {
    std::hash<decltype( this )> hasher;
    return ( ( this == &rhs ) || hasher( this ) == hasher( &rhs ) );
}

bool DCFMetaObject::operator !=( const DCFMetaObject & rhs ) const {
    return !( this->operator==( rhs ) );
}

bool DCFMetaObject::operator ==( const DCFMetaObject * rhs ) const {
    std::hash<decltype( this )> hasher;
    
    return ( ( this == rhs ) || hasher( this ) == hasher( rhs ) );
}

bool DCFMetaObject::operator !=( const DCFMetaObject * rhs ) const {
    return !( this->operator==( rhs ) );
}

//std::ostream & operator<<( std::ostream &os, const DCFMetaObject & rhs ) {
//    os << rhs.description();
//    
//    return os;
//}
//
//std::ostream & operator<<( std::ostream &os, const DCFMetaObject * rhs ) {
//    os << rhs->description();
//    
//    return os;
//}

DCF_NAMESPACE_END
