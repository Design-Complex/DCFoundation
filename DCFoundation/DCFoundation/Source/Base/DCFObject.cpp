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

DCF_NAMESPACE_BEGIN

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
    
    const char * myType = typeid( *this ).name();
    
    
    ss << "<[";
    ss << myType;
    ss << "@";
    ss << static_cast<const void *>( this );
    ss << "]>";
    
    return ss.str();
}

DCF_NAMESPACE_END
