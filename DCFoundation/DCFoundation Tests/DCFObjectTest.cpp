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

class MyObject : public DCFObject {
private:
    uint64_t _foo = UINT64_MAX;
    
protected:
    virtual ~MyObject() {}
    
public:
    MyObject() {
        this->init();
    }
    
    virtual const DCFHashCode hash() const {
        return 1 - ( _foo ^ this->retainCount() );
    }
    
    virtual MyObject * init() {
        if( this->DCFObject::init() ) {
            
        }
        
        return this;
    }
    
    MyObject * operator++() {
        ++_foo;
        
        return this;
    }
};


TEST_F( DCFObjectTest, objectLifetime ) {
    MyObject * mine = new MyObject;
        
        ASSERT_EQ( mine->retainCount(), 1 );
        
        mine->retain();
        
        ASSERT_EQ( mine->retainCount(), 2 );
        
        mine->release();
        
        ASSERT_EQ( mine->retainCount(), 1 );
        
        mine->release();
        
    ASSERT_THROW( mine->retainCount(), std::runtime_error );
    
}


TEST_F( DCFObjectTest, className ) {
    MyObject * obj = new MyObject;
    
    ASSERT_EQ( obj->className(), "DCF::Test::MyObject" );
    
    obj->release();
}

#if 0

TEST_F( DCFObjectTest, streamOps ) {
    MyObject * obj = new MyObject;
    MyObject & obj2 = *obj;
    
    std::cout << obj << std::endl;
    std::cout << obj2 << std::endl;
}

TEST_F( DCFObjectTest, description ) {
    MyObject * obj = new MyObject;
    
    ASSERT_NE( obj->description(), "" );
    
    obj->release();
}

TEST_F( DCFObjectTest, debugDescription ) {
    MyObject * obj = new MyObject;
    
    ASSERT_NE( obj->debugDescription(), "" ) << "Didn't return a description!";
    
    std::ostringstream oss;
    oss << "<" << obj->className() << "@" << static_cast<void const *>( &( *obj ) ) << ">";
    std::cout << oss.str() << std::endl;
    
    ASSERT_EQ( obj->debugDescription(), oss.str() ) << "Invalid format";
    
    obj->release();
}



TEST_F( DCFObjectTest, hashTest ) {
    MyObject * obj = new MyObject;
    MyObject * obj2 = new MyObject;
    
    DCFHashCode one, two;
    
    one = std::hash<uint64_t>()( UINT64_MAX );
    two = std::hash<uint64_t>()( 0 );
    
    ASSERT_NE( one, two );
    
//    
//    one = std::hash<MyObject *>()( obj );
//    two = std::hash<MyObject *>()( obj2 );
//        //ASSERT_NE( one, two ) << "Hash codes shouldn't be equal because pointers are different!";
//    
//    one = obj->hash();
//    two = obj->hash();
//    ASSERT_EQ( one, two ) << "Hash codes should be equal because the objects are equivalent";
//    
//    DCFHashable * h = dynamic_cast<DCFHashable *>( obj2 );
//    one = obj2->DCFHashable::hash();
//    two = h->hash();
//    
//    std::cout << one << " " << two << std::endl;
//    
//        // These two objects should be identical...
//    ASSERT_NE( obj, obj2 );
//    ASSERT_TRUE( *obj == obj ) << "Hash codes should be equal because the objects are equivalent";
//    ASSERT_TRUE( *obj == obj2 )  << "Hash codes should be equal because the objects are equivalent";
//    
//    ++obj2;
//    two = obj2->hash();
//    
//    ASSERT_FALSE( obj->hash() == obj2->hash() );
//    ASSERT_FALSE( obj == obj2 ) << "Objects should no longer be equivalent!";
}

#endif

DCF_TEST_NAMESPACE_END
