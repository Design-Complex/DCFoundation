//
//  DCFMetaClassBase.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFMetaClassBase.h"
#include "DCFMetaClass.h"
#include "DCFObject.h"
#include "DCFString.h"
#include "DCFSymbol.h"

#pragma mark RTTI

DCFMetaClassBase * DCFMetaClassBase::safeMetaCast( const DCFMetaClassBase * fromClass, const DCFMetaClass * toClass ) {
    
    if( toClass == nullptr ) {
        // TODO: Assert toClass != nullptr
        
        return const_cast<DCFMetaClassBase *>( fromClass );
    }

    return ( fromClass != nullptr ) ? fromClass->metaCast( toClass ) : nullptr;
}

bool DCFMetaClassBase::checkTypeInstance( const DCFMetaClassBase * instance, const DCFMetaClassBase *typeInstance ){
    
    if( typeInstance == nullptr ) {
            // TODO: Assert typeInstance != nullptr
        
        return false;
    }
    
    const DCFMetaClass * toType = typeInstance->metaClass();
    
    return toType && ( instance->metaCast( toType ) != nullptr );
}

DCFMetaClassBase * DCFMetaClassBase::metaCast( const DCFMetaClass * toClass ) const {
    
        // TODO: Fill me in!
    return nullptr;
}
