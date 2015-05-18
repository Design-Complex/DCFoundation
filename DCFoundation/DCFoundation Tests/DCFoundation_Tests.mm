//
//  DCFoundation_Tests.m
//  DCFoundation Tests
//
//  Created by Rob Dotson on 5/18/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import <DCFoundation/DCFoundation.h>
#import <DCFoundation/DCFObject.h>
#import <gtest/gtest.h>

static std::recursive_mutex lock;

using DCFMutexGuard = std::lock_guard<std::recursive_mutex>;

@interface DCFoundation_Tests : XCTestCase

@end

@implementation DCFoundation_Tests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

-( void )testMainThread {
    XCTAssertTrue( DCF::getMainThread() == DCF::currentThreadID(), @"Thread IDs are not equal!" );
    
    std::thread t( [=]() {
        XCTAssertFalse( DCF::isMainThread(), @"This should have spawned a new thread!" );
    });
    t.join();
}

@end

unsigned int func( unsigned int i ) {
    DCF::DCFMutexGuard g( lock );
    std::cout << "I'm " << i << " " << ( DCF::isMainThread()  ? "" : "not " ) << "the main thread!" << std::endl;
    DCF::DCFObject toast;
    
    return i;
}

TEST(foo, bar) {
    ASSERT_EQ( 1, 1 );
    
    int i = func( 1 );
}

TEST( thread, mainThread ) {
    ASSERT_EQ( DCF::getMainThread(), DCF::currentThreadID() );
    
    ASSERT_TRUE( DCF::isMainThread( DCF::currentThreadID() ) );
}