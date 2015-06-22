//
//  DCFDarwinPlatform.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#ifndef __DCFDarwinPlatform__
#define __DCFDarwinPlatform__

/*! \file */

#define __DARWIN__

#pragma mark Includes

#include <Availability.h>
#include <AvailabilityMacros.h>
#include <TargetConditionals.h>
#include <DCFoundation/DCFPlatform.h>

DCF_NAMESPACE_DEFINE( DCF ) DCF_NAMESPACE_DEFINE( System )

#pragma mark Class Definitions

class DCF_VISIBLE DarwinPlatform : public DCFPlatform {
    DCFSingletonDeclare( DarwinPlatform );
    
public:
    virtual size_t numberOfCores() const;
    
}; // DCF::System::Darwin

DCF_NAMESPACE_END DCF_NAMESPACE_END

#pragma mark Concrete Type Definitions

typedef DCF::System::DarwinPlatform DCFDarwinPlatform;

#endif // __DCFDarwinPlatform__
