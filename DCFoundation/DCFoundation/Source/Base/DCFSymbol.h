//
//  DCFSymbol.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFSymbol_
#define _DCFSymbol_

/*!
 * @header
 *
 * @abstract FILL ME IN
 */

#pragma mark Includes

#include <DCFoundation/DCFString.h>

DCF_NAMESPACE_BEGIN

#pragma mark - Forward Declarations


#pragma mark - Class Declaration

/*!
 * @class DCFSymbol
 *
 * @abstract FILL ME IN
 *
 * @discussion FILL ME IN
 */

class DCF_VISIBLE Symbol : public DCFString {
#pragma mark - Instance Variables

public:
    using DCFString::String;
    
}; // DCF::MetaClass

DCF_NAMESPACE_END

#pragma mark Concrete Type Declarations

typedef DCF::Symbol DCFSymbol;

#endif // _DCFSymbol_
