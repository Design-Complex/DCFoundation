//
//  DCFMetaClass.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFMetaClass.h"

#include <DCFoundation/DCFSymbol.h>

DCF_NAMESPACE_BEGIN


MetaClass::MetaClass( const DCFSymbol * className, const MetaClass * superClass, size_t classSize ) : _className( className ), _superClass( superClass ), _classSize( classSize ) {
    
}

MetaClass::~MetaClass() {
    
}

void MetaClass::operator delete( void *, size_t ) {
    
}

DCFRetainCount MetaClass::retainCount() const {
    return 0;
}

void MetaClass::retain() const {

}

void MetaClass::taggedRetain( const void * tag ) const {
#pragma unused(tag)
}

void MetaClass::release() const {
    
}

void MetaClass::releaseWhen( DCFRetainCount freeWhen ) const {
#pragma unused(freeWhen)
}

void MetaClass::taggedRelease( const void * tag ) const {
#pragma unused(tag)
}

DCF_NAMESPACE_END
