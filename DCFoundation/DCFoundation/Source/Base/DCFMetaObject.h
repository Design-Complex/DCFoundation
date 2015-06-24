//
//  DCFMetaObject.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFMetaObject_
#define _DCFMetaObject_

#include <DCFoundation/DCFMacros.h>
#include <DCFoundation/DCFPlatform.h>
#include <string>
#include <vector>
#include <iostream>

DCF_NAMESPACE_BEGIN

class DCF_VISIBLE MetaObject {
public:
    DCFDeclareAbstractDestructor( MetaObject );
    
    /** Returns a string representation of the object.
     @return A std::string reference
     */
    virtual std::string description() const;
    
    /**
     * Returns a string description of debug information for this object instance.
     * @return std::string in the format <className@0x0000000>contents</obj>
     */
    virtual std::string debugDescription() const;
    
    /**
     Returns an array of std::strings describing each segment of a full class name (including namespaces). A for a class in the DCF namespace, this method will return an array with the following: arr[0] = "DCF", arr[2] = "DCFObject"
     
     */
    virtual std::vector<std::string> & classPath() const;
    
        /// Returns a string containing the unmangled type name of the object.
    virtual const std::string & className() const;
    
        /// Returns true if the classes are equal
    virtual bool operator ==( const MetaObject & rhs ) const;
    
        /// Returns true if the classes are not equal. The default implementation calls !(operator==).
    virtual bool operator !=( const MetaObject & rhs ) const;
    
        /// Returns true if the pointers to both objects are equal. If they are *equivalent* meaning the hash codes are the same, this also returns true. If this is not desired behavior, subclasses SHOULD override this method.
    virtual bool operator ==( const MetaObject * rhs ) const;
    
        /// Returns true only if the hash values of the two pointers is not equal.
    virtual bool operator !=( const MetaObject * rhs ) const;
    
}; // DCFMetaObject

    /// Generic output operators
    /// Notice they are NOT friends. They call rhs->description() for printing.
//std::ostream & operator<<( std::ostream &os, const MetaObject & rhs );
//std::ostream & operator<<( std::ostream &os, const MetaObject * rhs );

DCF_NAMESPACE_END

typedef DCF::MetaObject DCFMetaObject;



#endif // _DCFMetaObject_
