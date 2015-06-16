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

typedef std::size_t  DCFHashCode;

class DCF_VISIBLE DCFHashable {
    DCFDeclareAbstractDestructor( DCFHashable );
    
        /// Returns a DCFHashCode for the instance. Classes adopting this interface MUST override this method.
    virtual const DCFHashCode hash() const = 0;
};

DCF_NAMESPACE_END

#endif // _DCFHashable_
