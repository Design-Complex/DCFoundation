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

DCFDefineAbstractDestructor( Object );
DCFDefineAbstractDestructor( Hashable );

#pragma mark - Object Lifetime

void * DCFObject::operator new( size_t size ) {
        // TODO: There's got to be more of it than this
    void * mem = malloc( size );
    if( mem ) {
        bzero( mem, size );
    }
    
    return ( mem );
}

void DCFObject::operator delete( void * mem ) {
    
    free( mem );
}

Object * DCFObject::init() {
    if( _retainCount > 0 )
        throw std::runtime_error( "Attempt to re-initialize class" );
    
    return this->retain();
}

size_t DCFObject::retainCount() const {
    return _retainCount.load();
}

Object * DCFObject::retain() {
    _retainCount.fetch_add( 1 );
    
    return this;
}

Object * DCFObject::release() {
    size_t result = _retainCount.fetch_sub( 1 );
    if( result == 0 ) { // We've over released!
        delete this;
    }
    
    return this;
}

#pragma mark - DCFHashable Implementation

const DCFHashCode DCFHashable::hash() const {
    return std::hash<decltype(this)>()( this );
}

#pragma mark - Public Members

#pragma mark Comparison Operators

bool DCFObject::operator ==( const DCFObject & rhs ) const {
    return ( this->hash() == rhs.hash() );
}

bool DCFObject::operator !=( const DCFObject & rhs ) const {
    return !( this->operator==( rhs ) );
}

bool DCFObject::operator ==( const DCFObject * rhs ) const {
    if( this == rhs )
        return true;
    
    return ( this->hash() == rhs->hash() );
}

bool DCFObject::operator !=( const DCFObject * rhs ) const {
    return !( this->operator==( rhs ) );
}

DCF_NAMESPACE_END
