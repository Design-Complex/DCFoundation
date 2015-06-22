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

#include <DCFoundation/DCFMetaObject.h>
#include <DCFoundation/DCFHashable.h>
#include <atomic>

DCF_NAMESPACE_BEGIN

#pragma mark - Class Interface

/**
 @class DCFObject
 @brief An abstract base class that all public DCFObjects inherit from.
 @namespace DCF
 */
class DCF_VISIBLE Object : public virtual DCFMetaObject, public virtual DCFHashable {
    DCFDeclareAbstractDestructor( Object );
    
private:
    std::atomic<size_t>      _retainCount   = ATOMIC_VAR_INIT( 0 );
    
protected:
    static void * operator new( size_t size );
    static void operator delete( void * mem );
        //static Object * alloc();
    
        // The default initializer. Subclasses MUST override this method, and should call this method FIRST by default.
    virtual Object * init() = 0;
    
public:
    
#pragma mark Object Lifetime
    
    virtual size_t retainCount() const;
    virtual Object * retain();
    virtual Object * release();
    
#pragma mark Comparison Operators
        /// Returns true if the classes are equal
    virtual bool operator ==( const Object & rhs ) const;
    
        /// Returns true if the classes are not equal. The default implementation calls !(operator==).
    virtual bool operator !=( const Object & rhs ) const;
    
        /// Returns true if the pointers to both objects are equal. If they are *equivalent* meaning the hash codes are the same, this also returns true. If this is not desired behavior, subclasses SHOULD override this method.
    virtual bool operator ==( const Object * rhs ) const;
    
        /// Returns true only if the hash values of the two pointers is not equal.
    virtual bool operator !=( const Object * rhs ) const;
    
    
#pragma mark DCFHashable Declarations
    /// Returns a DCFHashCode for the instance. Subclasses MUST override this method.
    using DCFHashable::hash;
    
}; // class DCFObject

DCF_NAMESPACE_END

typedef DCF::Object     DCFObject;

#endif // __DCFObject__
