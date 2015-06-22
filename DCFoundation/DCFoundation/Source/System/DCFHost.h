//
//  DCFHost.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/22/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFHost_
#define _DCFHost_

#include <DCFoundation/DCFMacros.h>
#include <DCFoundation/DCFDefines.h>

/*! \file */

DCF_NAMESPACE_DEFINE( DCF ) DCF_NAMESPACE_DEFINE( System )

#pragma mark - Class Declaration

class DCF_VISIBLE Host  {
    DCFPrivateConstructors( Host );
    
public:
    virtual ~Host();
    
    static Host * currentHost();
    
    
    virtual size_t numberOfCores() const = 0;
    
    virtual bool hasCommandProcessor() const;
    virtual int runSystemCommand( const char * cmd );
};

DCF_NAMESPACE_END DCF_NAMESPACE_END

#pragma mark Concrete Type Declarations

typedef DCF::System::Host DCFHost;

#endif // _DCFHost_
