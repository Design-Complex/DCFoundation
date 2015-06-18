//
//  DCFPlatform.cpp
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#include "DCFPlatform.h"

DCF_NAMESPACE_DEFINE( DCF ) DCF_NAMESPACE_DEFINE( System )

DCFPlatform::Platform() {}
DCFPlatform::~Platform() {}

DCFPlatform & DCFPlatform::sharedInstance() {
#if defined( __DARWIN__ )
    return DCFDarwinPlatform::sharedInstance();
#elif defined( __WINDOWS__ )
    return DCFWindowsPlatform::sharedInstance();
#elif defined( __LINUX__ )
    return DCFLinuxPlatform::sharedInstance();
#else
        // unknown platform!
#endif
}

DCF_NAMESPACE_END DCF_NAMESPACE_END
