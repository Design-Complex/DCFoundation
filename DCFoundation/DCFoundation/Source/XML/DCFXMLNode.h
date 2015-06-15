//
//  DCFXMLNode.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/15/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFXMLNode_
#define _DCFXMLNode_

#include <DCFoundation/DCFObject.h>
#include <DCFoundation/DCFXMLBase.h>

DCF_NAMESPACE_BEGIN DCF_XML_NAMESPACE_BEGIN

class Node : public virtual DCF::DCFObject {
public:
    typedef enum : size_t {
        INVALID                 = 0,
        DOCUMENT                = 1,
        ELEMENT                 = 2,
        ATTRIBUTE               = 3,
        PROCESSING_INSTRUCTION  = 4,
        COMMENT                 = 5,
        TEXT                    = 6,
        CDATA                   = 7,
        DOCUMENT_FRAGMENT       = 8,
        ENTITY                  = 9,
        ENTITY_REFERENCE        = 10,
        DOCUMENT_TYPE           = 11,
        WHITESPACE              = 12,
        NOTATION                = 13,
        ELEMENT_TYPE            = 14,
        ATTRIBUTE_LIST          = 15
    } typeCode;
    
protected:
    typeCode    _type   = INVALID;
    
public:
    typeCode type() const;
    
}; // Node

DCF_XML_NAMESPACE_END DCF_NAMESPACE_END

#endif // _DCFXMLNode_
