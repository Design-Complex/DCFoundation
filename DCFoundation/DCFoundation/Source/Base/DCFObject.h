//
//  DCFObject.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

/** @file */

#ifndef __DCFObject__
#define __DCFObject__

#pragma mark - Includes

#include <DCFoundation/DCFBase.h>

#include <vector>

DCF_NAMESPACE_BEGIN

#pragma mark - Type Definitions

#pragma mark - Forward Declarations

#pragma mark - Class Interface

/**
    @class DCFObject
    @brief An abstract base class that all public DCFObjects inherit from.
    @namespace DCF
 */
class DCF_VISIBLE DCFObject {
    
#pragma mark - Protected Members
protected:
    
    
#pragma mark - Public Members
    
public:
    
#pragma mark Constructors
    
        /// The default constructor for a DCFObject and its subclasses.
    DCFObject();
    
#pragma mark Destructor
    
        /// The destructor for the DCFObject
    virtual ~DCFObject();
    
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
    
        /// Returns a DCFHashCode for the instance. Subclasses MUST override this method.
    virtual const DCFHashCode hash() const = 0;
    
        /// Returns true if the classes are equal
    virtual bool operator ==( const DCFObject & rhs ) const;
    
        /// Returns true if the classes are not equal. The default implementation calls !(operator==).
    virtual bool operator !=( const DCFObject & rhs ) const;
    
        /// Returns true if the pointers to both objects are equal. If they are *equivalent* meaning the hash codes are the same, this also returns true. If this is not desired behavior, subclasses SHOULD override this method.
    virtual bool operator ==( const DCFObject * rhs ) const;
    
        /// Returns true only if the hash values of the two pointers is not equal.
    virtual bool operator !=( const DCFObject * rhs ) const;
    
}; // class DCFObject

DCF_NAMESPACE_END

#endif // __DCFObject__
