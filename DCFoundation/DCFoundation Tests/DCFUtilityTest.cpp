//
//  DCFUtilityTest.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/4/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFTesting.h"
#include <DCFoundation/DCFUtility.h>
#include <DCFoundation/DCFObject.h>

DCF_TEST_NAMESPACE_BEGIN

class DCFUtilityTest : public ::testing::Test {};

using namespace DCF;

TEST_F( DCFUtilityTest, demangleIdentifier ) {
    DCFObject obj;
    
    std::string correct = "DCF::DCFObject";
    
    ASSERT_EQ( correct, obj.className() );
    
    ASSERT_EQ( correct, DCFDemangleIdentifier( typeid( DCFObject ).name() ) );
}

DCF_TEST_NAMESPACE_END