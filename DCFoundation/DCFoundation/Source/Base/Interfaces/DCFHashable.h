//
//  DCFHashable.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFHashable_
#define _DCFHashable_

/*! \file */

#include <DCFoundation/DCFMacros.h>

DCF_NAMESPACE_BEGIN

#pragma mark Type Definitions

typedef std::size_t  HashCode;

class DCF_VISIBLE Hashable {
    DCFDeclareAbstractDestructor( Hashable );
    
        /// Returns a DCFHashCode for the instance. Classes adopting this interface MUST override this method.
    virtual const HashCode hash() const = 0;
};

DCF_NAMESPACE_END

#define DCFMakeHashable() virtual const DCFHashCode hash() const

typedef DCF::HashCode DCFHashCode;
typedef DCF::Hashable DCFHashable;

#endif // _DCFHashable_
