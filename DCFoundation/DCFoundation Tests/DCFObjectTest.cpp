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
    DCFObject obj;
    
    ASSERT_EQ( obj.className(), "DCF::DCFObject" );
}

TEST_F( DCFObjectTest, description ) {
    
}

TEST_F( DCFObjectTest, debugDescription ) {
    DCFObject obj;
    
    ASSERT_NE( obj.debugDescription(), "" ) << "Didn't return a description!";
    
    std::ostringstream oss;
    oss << "<" << obj.className() << "@" << &obj << ">";
    
    ASSERT_EQ( obj.debugDescription(), oss.str() ) << "Invalid format";
    
    
    
}

DCF_TEST_NAMESPACE_END
