//
//  DCFObjectTest.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 5/19/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFTesting.h"
#include <DCFoundation/DCFObject.h>

DCF_TEST_NAMESPACE_BEGIN

class DCFObjectTest : public ::testing::Test {
    
};

TEST_F( DCFObjectTest, className ) {
    
}

TEST_F( DCFObjectTest, description ) {
    
}

TEST_F( DCFObjectTest, debugDescription ) {
    DCFObject obj;
    DCFObject obj2;
    
    ASSERT_TRUE( &obj != nullptr ) << "Uh oh!";
    
    
}

DCF_TEST_NAMESPACE_END
