//
//  DCFMacros.h
//  DCFoundation
//
//  Created by Rob Dotson on 4/2/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

/*! \file */

#ifndef _DCFMacros_
#define _DCFMacros_

#pragma mark - C

#define DCF_EXTERN extern

#if defined( __cplusplus )

#define DCF_EXTERN_C DCF_EXTERN "C"
#define DCF_EXTERN_C_BEGIN  DCF_EXTERN_C {
#define DCF_EXTERN_C_END    }

#endif // defined( __cplusplus )

#pragma mark - C++

#define DCF_CPP98 ( __cplusplus >= 199711L )
#define DCF_CPP11 ( __cplusplus >= 201103L )
#define DCF_CPP14 ( __cplusplus >= 201402L )

#if DCF_CPP11

#define DCFPrivateCopyAndAssign( TypeName ) \
private: \
TypeName( const TypeName & ) =delete; \
TypeName & operator=( const TypeName & ) =delete; //\
\\void operator=( const TypeName & ) =delete

#define DCFPrivateConstructors( TypeName ) \
private: \
TypeName(); \
DCFPrivateCopyAndAssign( TypeName )

#else

#define DCFPrivateCopyAndAssign( TypeName ) \
private: \
TypeName( const TypeName & ); \
TypeName & operator=( const TypeName & ) \
void operator=( const TypeName & )

#define DCFPrivateConstructors( TypeName ) \
private: \
TypeName(); \
DCFPrivateCopyAndAssign( TypeName )

#endif // DCF_CPP11

#pragma mark - Namespace

/** @def DCF_NAMESPACE_BEGIN
    @brief The declaration tag for the DCF Namespace. It must be included in all framework files before any types, classes, functions or variables are declared or defined.
 */
#define DCF_NAMESPACE_BEGIN namespace DCF {

/*! @def DCF_NAMESPACE_END
    @brief The closing declaration tag for the DCF Namespace. It must be included in all framework files after any types, classes, functions or variables are declared or defined.
 */
#define DCF_NAMESPACE_END }

#pragma mark - Compiler Macros

    /// Should this symbol be exported?

#define DCF_VISIBLE     __attribute__((visibility("default")))
#define DCF_INVISIBLE   __attribute__((visibility("hidden")))

#define DCF_EXPORT      DCF_EXTERN DCF_VISIBLE
#define DCF_NOEXPORT    DCF_INVISIBLE

#define DCF_IMPORT      DCF_EXTERN

    /*! @def DCF_THIS_TYPE
        @brief A macro which compiles to typeid(*this)
     */
#define DCF_THIS_TYPE   typeid( *this )

#define DCF_DEPRECATED  __attribute__((deprecated))

#define DCF_LIBRARY_INITIALIZER __attribute__((constructor))

#define DCF_LIBRARY_FINALIZER   __attribute__((destructor))

#define DCF_WARN(x) warning( #x )

#define DCF_TODO(x) DCF_WARN( "TODO: ", #x )

#define DCF_ASSERT(x) \
if( !( x ) ) { \
std::cout << "DCFError: Assertion " << #x << " failed!" << std::endl; \
std::cout << "\ton line " << __LINE__ << std::endl; \
std::cout << "\tin file " << __FILE__ << std::endl; \
}

#pragma mark - Processor Alignment

#define DCF_ALIGN_TLS   __declspec(thread)
#define DCF_ALIGN_64    __declspec(align(64))
#define DCF_ALIGN_32    __declspec(align(32))
#define DCF_ALIGN_16    __declspec(align(16))
#define DCF_ALIGN_00    __unaligned

#endif // _DCFMacros_
