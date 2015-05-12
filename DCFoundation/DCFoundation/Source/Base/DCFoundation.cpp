
#import <DCFoundation/DCFoundation.h>
#import <mutex>
#import <gtest/gtest.h>
#import <DCFoundation/DCFObject.h>



static std::recursive_mutex lock;

using DCFMutexGuard = std::lock_guard<std::recursive_mutex>;

class foo {
    foo() {}
};

unsigned int func( unsigned int i ) {
    DCFMutexGuard g( lock );
    std::cout << "I'm " << i << " " << ( DCF::isMainThread()  ? "" : "not " ) << "the main thread!" << std::endl;
    
    DCF::DCFObject obj;
    std::string str = obj.debugDescription();
    
    std::cout << str << std::endl;
    
    
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

TEST( thread, notMainThread ) {
    std::thread t( []() {
        ASSERT_FALSE( DCF::isMainThread() );
    });
    t.join();
}

//int main( int argc, char ** argv, char ** envp ) {
//    func( 0 );
//    
//    std::thread t( func, 1 );
//    t.detach();
//    
//    std::thread t1( []() -> int { return func( 2 ); } );
//    t1.join();
//    
//    auto h3 = std::async( std::launch::async, func, 3 );
//    auto h4 = std::async( std::launch::async, []()->int { return func( 4 ); } );
//    auto h5 = std::async( std::launch::any, []()-> int{ return func( 5 ); } );
//    
//    {
//        DCFMutexGuard g( lock );
//        std::cout << h3.get() << h4.get() << h5.get() << std::endl;
//    }
//    
//    
////    while( *envp != nullptr )
////        std::cout << *envp++ << "\n";
////    
////    std::cout << std::endl;
//    
//    return EXIT_SUCCESS;
//}