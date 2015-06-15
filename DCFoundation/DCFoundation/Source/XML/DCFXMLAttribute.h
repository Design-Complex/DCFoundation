//
//  DCFXMLAttribute.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/15/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFXMLAttribute_
#define _DCFXMLAttribute_

#include <DCFoundation/DCFXMLBase.h>

DCF_NAMESPACE_BEGIN DCF_XML_NAMESPACE_BEGIN

const char * AttributeCDATAType     = "CDATA";
const char * AttributeIDType        = "ID";
const char * AttributeIDREFType     = "IDREF";
const char * AttributeNMTOKENType   = "NMTOKEN";
const char * AttributeNMTOKENSType  = "NMTOKENS";
const char * AttributeENTITYType    = "ENTITY";
const char * AttributeENTITIESType  = "ENTITIES";

class Attribute {
public:
    typedef enum : size_t {
        CDATA,
        ID,
        IDREF,
        NMTOKEN,
        NMTOKENS,
        ENTITY,
        ENTITIES
    } AttributeType;
    
    Attribute();
    
    const std::string & URI() const;
    
    const std::string & localName() const;
    
    const std::string & qualifiedName() const;
    
    const std::string & type() const;
    
    const std::string & value() const;
    
protected:
    AttributeType   _type;
    
}; // _DCFXMLAttribute_

DCF_XML_NAMESPACE_END DCF_NAMESPACE_END

#endif // _DCFXMLAttribute_
