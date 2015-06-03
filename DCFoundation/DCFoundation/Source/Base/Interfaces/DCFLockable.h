//
//  DCFLockable.h
//  DCFoundation
//
//  Created by Rob Dotson on 6/3/15.
//  Copyright (c) 2015 Design Complex LLC. All rights reserved.
//

#ifndef _DCFLockable_
#define _DCFLockable_

#pragma mark - Includes

#include <DCFoundation/DCFDefines.h>
#include <DCFoundation/DCFMacros.h>

#include <mutex>

DCF_NAMESPACE_BEGIN

#pragma mark - Type Definitions

    /// A Mutex class
using DCFMutex = std::mutex;
using DCFRecursiveMutex = std::recursive_mutex;

    /// A Mutex guard
using DCFMutexGuard = std::lock_guard<DCFMutex>;
using DCFRecursiveMutexGuard = std::lock_guard<DCFRecursiveMutex>;

#pragma mark - Forward Declarations

#pragma mark - Class Interface

/**
 @class DCFLockable
 @brief An abstract interface template for lockable classes. Template parameter LockType should be the std::mutex type to be embedded in the object.
 @namespace DCF
 */

template <typename LockType>
class DCF_VISIBLE DCFLockable {
private:
        /// The basic lock.
    LockType _lock;
    
protected:
        /// Only subclasses should be able to access the lock directly.
    virtual LockType & theLock() final { return _lock; }
    
public:
        /// The default constructor
    explicit DCFLockable() : _lock() {}

        /// The copy constructor. A new lock is returned instead of a copy.
    DCFLockable( const DCFLockable<LockType> & rhs ) : DCFLockable::DCFLockable() {
        if( !const_cast<DCFLockable<LockType> &>(rhs).tryLock() )
            throw std::runtime_error( "Attempt to copy construct a locked object!" );
        
        const_cast<DCFLockable<LockType> &>(rhs).unlock();
    }

        /// The move constructor. A new lock is always returned. Throws a runtime exception if an attempt is made to copy a locked object
    DCFLockable( const DCFLockable<LockType> && rhs ) : DCFLockable::DCFLockable() {
        if( !const_cast<DCFLockable<LockType> &&>(rhs)._lock.try_lock() )
            throw std::runtime_error( "Attempt to move construct a locked object!" );
        
        const_cast<DCFLockable<LockType> &&>(rhs).unlock();
    }

        /// The copy assignment operator. Always makes a copy of the lock. This throws a runtime exception if you attempt to assign or copy a locked object.
    DCFLockable<LockType> & operator=( const DCFLockable<LockType> & rhs ) {
        if( !const_cast<DCFLockable<LockType> &>(rhs)._lock.try_lock() )
            throw std::runtime_error( "Attempt to copy a locked object!" );
        
        const_cast<DCFLockable<LockType> &>(rhs).unlock();
        
        return *this;
    }

        /// The move assignment operator. Always makes a copy of the lock. This throws a runtime exception if you attempt to assign or copy a locked object.
    DCFLockable<LockType> & operator=( const DCFLockable<LockType> && rhs ) {
        if( !const_cast<DCFLockable<LockType> &&>(rhs).tryLock() )
            throw std::runtime_error( "Attempt to move a locked object!" );
        
        const_cast<DCFLockable<LockType> &&>(rhs).unlock();
        
        return *this;
    }

        /// The virtual destructor
    virtual ~DCFLockable() {}
    
        /// Lock the mutex
    virtual void lock() noexcept { _lock.lock(); }

    /// Try to lock the mutex
    virtual bool tryLock() noexcept  { return _lock.try_lock(); }
    
        /// Unlock the mutex
    virtual void unlock() noexcept { _lock.unlock(); }
    
};


DCF_NAMESPACE_END

#endif // _DCFLockable_
