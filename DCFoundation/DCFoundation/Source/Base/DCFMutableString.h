//
//  DCFMutableString.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/24/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFMutableString_
#define _DCFMutableString_

#include <DCFoundation/DCFString.h>

DCF_NAMESPACE_BEGIN

class DCF_VISIBLE MutableString : public virtual DCFString {
    
}; // MutableString

DCF_NAMESPACE_END

typedef DCF::MutableString DCFMutableString;

#endif // _DCFMutableString_
