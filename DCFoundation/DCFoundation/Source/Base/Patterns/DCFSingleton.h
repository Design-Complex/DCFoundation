//
//  DCFSingleton.h
//  DCFoundation
//
//  Created by Rob Dotson on 4/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFSingleton_
#define _DCFSingleton_

/*! \file */

#include <DCFoundation/DCFBase.h>

#define DCFSingletonDeclare( TypeName ) \
private: \
DCFPrivateConstructors( TypeName ); \
static TypeName * _sharedInstance; \
static DCF::DCFMutex _lock; \
public: \
virtual ~TypeName(); \
static TypeName & sharedInstance();

#define DCFSingletonDefine( TypeName ) \
TypeName * TypeName::_sharedInstance = nullptr; \
DCF::DCFMutex TypeName::_lock; \
TypeName & TypeName::sharedInstance() { \
if( TypeName::_sharedInstance == nullptr ) { \
DCF::DCFMutexGuard guard( TypeName::_lock ); \
if( TypeName::_sharedInstance == nullptr ) \
TypeName::_sharedInstance = new TypeName(); \
} \
return *( TypeName::_sharedInstance ); \
} \

#endif // _DCFSingleton_
