//
//  DCFXMLAttributeList.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/15/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFXMLAttributeList_
#define _DCFXMLAttributeList_

#include <DCFoundation/DCFXMLBase.h>

DCF_NAMESPACE_BEGIN DCF_XML_NAMESPACE_BEGIN DCF_SAX_NAMESPACE_BEGIN

class AttributeList {
    
public:
    ~AttributeList() = 0; // Abstract Class
    
#pragma mark Interation Methods
    
        /// Return the number of attributes in this list
    size_t    length() const;
    
        /// Return the name of an attribute in this list by index.
    const std::string & name( const size_t index ) const;
    
        /// Return the type of an attribute in the list by index.
    const std::string & type( const size_t index ) const;
    
        /// Return the value of an attribute in the list by index.
    const std::string & value( const size_t index ) const;
    
#pragma mark Lookup Methods
    
        /// Return the type of an attribute in the list by name.
    const std::string & type( const std::string & name ) const;
    
        /// Return the value of an attribute in the list by name.
    const std::string & value( const std::string & name ) const;
    
}; // AttributeList

DCF_SAX_NAMESPACE_END DCF_XML_NAMESPACE_END DCF_NAMESPACE_END

#endif // _DCFXMLAttributeList_
