//
//  DCFMetaClassMacros.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/22/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#if !defined( _DCFMetaClassMacros_ )
#define _DCFMetaClassMacros_

/*! \file */

#include <DCFoundation/DCFMacros.h>

/* Not to be included in headerdoc.
 *
 * @define OSDeclareCommonStructors
 * @hidecontents
 *
 * @abstract
 * Helper macro for for the standard metaclass-registration macros.
 * DO NOT USE.
 *
 * @param className The name of the C++ class, as a raw token,
 *                  <i>not</i> a string or macro.
 */
#define DCFDeclareCommonStructors(className)                     \
    private:                                                    \
    static const DCFMetaClass * const superClass;                \
    public:                                                     \
    static const DCFMetaClass * const metaClass;                 \
        static class MetaClass : public DCFMetaClass {           \
        public:                                                 \
            MetaClass();                                        \
            virtual DCFObject *alloc() const;                    \
        } gMetaClass;                                           \
        friend class className ::MetaClass;                     \
        virtual const DCFMetaClass * getMetaClass() const;       \
    protected:                                                  \
    className (const DCFMetaClass *);                            \
    virtual ~ className ()


#endif // _DCFMetaClassDefines_
