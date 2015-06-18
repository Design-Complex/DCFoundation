//
//  DCFMetaClassBase.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFMetaClassBase_
#define _DCFMetaClassBase_

/*!
 * @header
 *
 * @abstract
 * This header declares the DCFMetaClass class,
 * which forms the basis of the DCFoundation C++ class hierarchy
 * and run-time type information facility.
 */

#pragma mark Includes

#include <DCFoundation/DCFMacros.h>
#include <DCFoundation/DCFDefines.h>

DCF_NAMESPACE_BEGIN

#pragma mark Forward Declarations

class DCFMetaClass;
class DCFObject;
class DCFString;
class DCFSymbol;

#pragma mark Type Definitions

typedef size_t RetainCount;

#pragma mark - Class Declaration
/*!
 * @class DCFMetaClassBase
 *
 * @abstract
 * DCFMetaClassBase is the abstract bootstrap class
 * for the DCFoundation run-time type information system.
 *
 * @discussion
 * DCFMetaClassBase is the abstract C++ root class
 * underlying the entire DCFoundation class hierarchy.
 * It defines the run-time type information system,
 * including dynamic class allocation and safe type-casting,
 * as well as the abstract interface for reference counting
 * and a few other utility functions.
 * OSMetaClassBase is the immediate superclass of
 * @link //apple_ref/doc/class/DCFObject DCFObject@/link and
 * @link //apple_ref/doc/class/DCFMetaClass DCFMetaClass@/link;
 * no other class should derive from DCFMetaClassBase.
 *
 * Code should never interact directly with DCFMetaClassBase,
 * but they will find useful several macros that tie in
 * to the run-time type information system, specifically:
 * <ul>
 * <li><code>@link OSTypeAlloc OSTypeAlloc@/link</code> - allocation of new instances</li>
 * <li><code>@link OSDynamicCast OSDynamicCast@/link</code> - safe type casting</li>
 * <li><code>@link OSCheckTypeInst OSCheckTypeInst@/link</code> -
 *     checking for inheritance/derivation</li>
 * <li><code>@link OSMemberFunctionCast OSMemberFunctionCast@/link</code> -
 *     casting C++ member functions to C function pointers
 *     for registration as callbacks</li>
 * </ul>
 *
 * See @link //apple_ref/doc/class/DCFMetaClass DCFMetaClass@/link
 * for more run-time type information interfaces.
 *
 * <b>Use Restrictions</b>
 *
 * DCFMetaClassBase should not be subclassed,
 * nor should objects call its run-time type functions directly.
 *
 * <b>Concurrency Protection</b>
 *
 * The run-time type macros and functions of DCFMetaClassBase are thread-safe.
 */

class MetaClassBase {

#pragma mark - Constructors, Destructors & Initializers
    
private:
    DCFPrivateCopyAndAssign( MetaClassBase );
    
protected:
    MetaClassBase();
    virtual ~MetaClassBase();
    
public:
    static void initialize( void );
    
#pragma mark Object Lifetime
public:
        // TODO: This should be compatible with std::smart_pointer
    virtual RetainCount retainCount() const = 0;
    virtual void retain() const = 0;
    virtual void taggedRetain( const void * tag = nullptr ) const = 0;
    
    virtual void release() const = 0;
    virtual void releaseWhen( RetainCount freeWhen ) const = 0;
    virtual void taggedRelease( const void * tag = nullptr ) const = 0;

protected:
    virtual void taggedRelease( const void * tag, const RetainCount freeWhen ) const = 0;
    
#pragma mark RTTI
public:
    virtual const DCFMetaClass * metaClass() const = 0;
    
    MetaClassBase * metaCast( const DCFMetaClass * toClass ) const;
    MetaClassBase * metaCast( const DCFSymbol * toClass ) const;
    MetaClassBase * metaCast( const DCFString * toClass ) const;
    MetaClassBase * metaCast( const char * toClass ) const;
    
    static MetaClassBase * safeMetaCast( const MetaClassBase * fromClass = nullptr, const DCFMetaClass * toClass = nullptr );
    
    static bool checkTypeInstance( const MetaClassBase * instance, const MetaClassBase * typeInstance );
    
    virtual bool operator==( const MetaClassBase * rhs ) const;
};

DCF_NAMESPACE_END

#pragma mark Concrete Type Declarations

typedef DCF::MetaClassBase  DCFMetaClassBase;
typedef DCF::RetainCount    DCFRetainCount;

#endif // _DCFMetaClassBase_
