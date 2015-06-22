//
//  DCFString.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/16/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFString_
#define _DCFString_

/*!
 * @header
 *
 * @abstract FILL ME IN
 */

#pragma mark Includes

#include <DCFoundation/DCFObject.h>
#include <string>

DCF_NAMESPACE_BEGIN

#pragma mark - Forward Declarations

#pragma mark - Class Declaration

/*!
 * @class DCFString
 *
 * @abstract FILL ME IN
 *
 * @discussion FILL ME IN
 */

class DCF_VISIBLE String : public virtual DCFObject {
public:
    typedef enum : uint64_t {
        kDCFStringASCIIEncoding     = 0,
        kDCFStringUTF8Encoding,
        kDCFStringUTF16Encoding,
        kDCFStringUTF32Encoding
    } Encoding;
    
#pragma mark - Instance Variables
private:
    
protected:
    DCFPlatformStringType _storage   = nullptr;
    
    String();
    String( const char * str );
    String( const std::string & str );
    String( const std::wstring & str );
    String( const std::u16string & str );
    String( const std::u32string & str );
    
    virtual String * init();
    virtual String * initWithString( const String * string );
    virtual String * initWithCString( const char * cstring );
    virtual String * initWithCStringNoCopy( const char * cstring );
    virtual String * initWithCStringOfLength( const char * cstring, size_t length );
    virtual String * initWithBytes( const uint8_t * buffer, size_t length, Encoding encoding );
    
public:
    virtual ~String();
    
    DCFMakeHashable();
    
    static String * withString( const String * str );
    static String * withCString( const char * cstr );
    static String * withCStringNoCopy( const char * cstr );
    static String * withCStringOfLength( const char * cstr, size_t length );
    static String * withBytes( const uint8_t * buffer, size_t length, Encoding encoding );
    
    DCFPlatformStringType platformString() const;
    
}; // DCF::MetaClass

DCF_NAMESPACE_END

#pragma mark Concrete Type Declarations

typedef DCF::String             DCFString;
typedef DCF::String::Encoding   DCFStringEncoding;

#endif // _DCFString_
