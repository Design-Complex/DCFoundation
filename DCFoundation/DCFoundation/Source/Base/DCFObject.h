//
//  DCFObject.h
//  DCFoundation
//
//  Created by Rob Dotson  on 4/10/15.
//  Copyright (c) 2015 Design Complex. All rights reserved.
//

#ifndef __DCFObject__
#define __DCFObject__

#include <DCFoundation/DCFBase.h>

DCF_NAMESPACE_BEGIN

class DCF_EXPORT DCFObject {
public:
    std::string description() const;
    std::string debugDescription() const;
};

DCF_NAMESPACE_END

#endif // __DCFObject__
