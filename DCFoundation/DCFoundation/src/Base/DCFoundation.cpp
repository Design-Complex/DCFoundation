
#import <DCFoundation/DCFoundation.h>

class foo {
    foo() {}
};

void func() {
    std::cout << "I'm " << ( std::this_thread::is_main_thread()  ? "" : "not" ) << " the main thread!" << std::endl;
}


int main( int argc, char ** argv, char ** envp ) {
    func();
    
    std::thread t( func );
    t.join();
    
    while( *envp != nullptr )
        std::cout << *envp++ << "\n";
    
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}