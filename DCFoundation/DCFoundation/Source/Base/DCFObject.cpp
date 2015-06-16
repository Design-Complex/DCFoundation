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

DCFDefineAbstractDestructor( DCFObject );
DCFDefineAbstractDestructor( DCFHashable );

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
