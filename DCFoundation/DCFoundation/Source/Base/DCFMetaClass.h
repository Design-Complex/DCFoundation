//
//  DCFMetaClass.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFMetaClass_
#define _DCFMetaClass_

/*!
 * @header
 *
 * @abstract FILL ME IN
 */

#pragma mark Includes

#include <DCFoundation/DCFMetaClassBase.h>

DCF_NAMESPACE_BEGIN

#pragma mark - Forward Declarations

class DCFMetaClassExpansionData;

#pragma mark - Class Declaration

/*!
 * @class DCFMetaClass
 *
 * @abstract FILL ME IN
 *
 * @discussion FILL ME IN
 */

class DCF_VISIBLE MetaClass : private DCFMetaClassBase {
#pragma mark - Instance Variables
private:
        /// For internal use only
    DCFMetaClassExpansionData *     _expansionData;
    
        /// The super class' meta class (this could be expanded).
    const MetaClass *            _superClass;
    
        /// The DCFSymbol of the class' name
    const Symbol *               _className;
    
        /// The size of the class
    size_t                          _classSize;
    
        /// Roughly the number of instances of the object
    size_t                          _instanceCount;
    
private:
        /// All metaclass instances are created at compile time
    static void * operator new( size_t size );
    
        /// Standard private constructor
    MetaClass();
    
protected:
        /// Default constructor
    explicit MetaClass( const Symbol * className, const MetaClass * superClass, size_t classSize );
    
        /// Destructor
    virtual ~MetaClass();
    
        /// DCFMetaClass objects are allocated at compile time don't try to free them
    void operator delete( void *, size_t );
    
#pragma mark Object Lifetime
    
    virtual RetainCount retainCount() const;
    virtual void retain() const;
    virtual void taggedRetain( const void * tag = nullptr ) const;
    
    virtual void release() const;
    virtual void releaseWhen( RetainCount freeWhen ) const;
    virtual void taggedRelease( const void * tag = nullptr ) const;
  
#pragma mark RTTI
        /// Returns the meta-meta cast
        ///
    virtual const MetaClass * metaClass() const;
    
public:
        /// Look up a meta class
    static const MetaClass * metaClassWithName( const Symbol * name );
    
}; // DCF::MetaClass

DCF_NAMESPACE_END

#pragma mark Concrete Type Declarations

typedef DCF::MetaClass DCFMetaClass;

#endif // _DCFMetaClass_
