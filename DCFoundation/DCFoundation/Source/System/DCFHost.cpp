//
//  DCFHost.cpp
//  DCFoundation
//
//  Created by Rob Dotson on 6/22/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#include "DCFHost.h"
#include "DCFConcurrency.h"
#include <cstdlib>

bool  DCFHost::hasCommandProcessor() const {
    return ( std::system( nullptr ) );
}

int DCFHost::runSystemCommand( const char * cmd ) {
    int result = EXIT_SUCCESS;
    std::thread t( [&result,cmd]{
        result = std::system( cmd );
    });
    t.join();
    
    return result;
}