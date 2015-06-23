//
//  DCFStringEncodings.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/23/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFStringEncodings_
#define _DCFStringEncodings_

#include <DCFoundation/DCFMacros.h>

DCF_EXTERN_C_BEGIN

#pragma mark Type Definitions

typedef uint32_t DCFStringEncoding;

#pragma mark Supported String Encodings

DCF_EXTERN const DCFStringEncoding kDCFStringEncodingMacRoman;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingWindowsLatin1;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingISOLatin1;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingNextStepLatin;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingASCII;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUnicode;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF8;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingNonLossyASCII;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF16;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF16BE;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF16LE;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF32;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF32BE;
DCF_EXTERN const DCFStringEncoding kDCFStringEncodingUTF32LE;

DCF_EXTERN_C_END

#endif // _DCFStringEncodings_
