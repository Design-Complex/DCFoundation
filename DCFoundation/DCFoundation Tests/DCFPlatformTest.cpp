//
//  DCFPlatformTest.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFTesting.h"
#include <DCFoundation/DCFPlatform.h>

DCF_TEST_NAMESPACE_BEGIN

class DCFPlatformTest : public ::testing::Test {
    
};

TEST_F( DCFPlatformTest, singleton ) {
    DCFPlatform & platform = DCFPlatform::sharedInstance();
    
    ASSERT_TRUE( platform.numberOfCores() > 0 ) << "Couldn't get the correct number of cores!";
}

DCF_TEST_NAMESPACE_END
