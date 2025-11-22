////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2024 Richard Ikin
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <format>

#include "ObjectMap.h"

#include <cstdint>

#include "../Logging/Logger.h"
#include "../../Maths/MathUtils.h"

template< typename Tk, typename Tv >
ObjectMap< Tk, Tv >::ObjectMap() : ObjectMap( DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR )
{
}

template< typename Tk, typename Tv >
ObjectMap< Tk, Tv >::ObjectMap( int initialCapacity )
    : ObjectMap( initialCapacity, DEFAULT_LOAD_FACTOR )
{
}

template< typename Tk, typename Tv >
ObjectMap< Tk, Tv >::ObjectMap( int initialCapacity, float loadFactor, bool debug )
{
    if ( loadFactor <= 0.0f || loadFactor >= 1.0f )
    {
        throw std::runtime_error( std::format( "loadFactor must be > 0 and < 1: {}", loadFactor ) );
    }

    loadFactor = loadFactor;

    int tableSize = TableSize( initialCapacity, loadFactor );

    mThreshold = static_cast< int >( static_cast< float >( tableSize ) * loadFactor );
    mMask      = tableSize - 1;
    mShift     = std::countl_zero( static_cast< unsigned int >( mMask ) );

    AllocateTables( tableSize );

    if ( debug )
    {
        Logger::Debug( std::format( "initialCapacity: {}", initialCapacity ) );
        Logger::Debug( std::format( "initialCapacity * loadFactor: {}", ( float )initialCapacity * loadFactor ) );
        Logger::Debug( std::format( "mKeyTable.Size: {}", std::size( GetKeys() ) ) );
        Logger::Debug( std::format( "ValueTable.Size: {}", std::size( GetValues() ) ) );
    }
}

template< typename Tk, typename Tv >
ObjectMap< Tk, Tv >::ObjectMap( const ObjectMap &otherMap )
    : ObjectMap( static_cast< int >( otherMap.mKeyTable.m_length * otherMap.mLoadFactor ), // Initial capacity
                 otherMap.mLoadFactor,                                                     // Load factor
                 false )
{
    mKeyTable   = otherMap.mKeyTable;
    mValueTable = otherMap.mValueTable;

    mSize = otherMap.mSize;
}

template< typename Tk, typename Tv >
int ObjectMap< Tk, Tv >::TableSize( int initialCapacity, float loadFactor )
{
    return MathUtils::NextPowerOfTwo( std::max( 2, ( int )std::ceil( ( float )initialCapacity / loadFactor ) ) );
}

template< typename Tk, typename Tv >
void ObjectMap< Tk, Tv >::AllocateTables( int initialCapacity )
{
    if ( initialCapacity <= 0 )
    {
        throw std::invalid_argument( "size must be > 0" );
    }

    // initialise the vectors to hold 'initial_capacity' number of elements.
    mKeyTable.reserve( initialCapacity );
    mValueTable.reserve( initialCapacity );

    mCapacity = initialCapacity;
    mSize     = 0;
}

// ==============================================
// Getters
// ==============================================

template< typename Tk, typename Tv >
int ObjectMap< Tk, Tv >::GetSize() const
{
    return mSize;
}

template< typename Tk, typename Tv >
bool ObjectMap< Tk, Tv >::GetAllocateIterators() const
{
    return mAllocateIterators;
}

template< typename Tk, typename Tv >
Tk ObjectMap< Tk, Tv >::GetKey( int index )
{
    return mKeyTable[ index ];
}

template< typename Tk, typename Tv >
Tv ObjectMap< Tk, Tv >::GetValue( int index )
{
    return mValueTable[ index ];
}

template< typename Tk, typename Tv >
Tk *ObjectMap< Tk, Tv >::GetKeys()
{
    return mKeyTable;
}

template< typename Tk, typename Tv >
Tv *ObjectMap< Tk, Tv >::GetValues()
{
    return mValueTable;
}

// ==============================================
// Setters
// ==============================================

template< typename Tk, typename Tv >
void ObjectMap< Tk, Tv >::SetSize( int value )
{
    mSize = value;
}

template< typename Tk, typename Tv >
void ObjectMap< Tk, Tv >::SetAllocateIterators( bool value )
{
    mAllocateIterators = value;
}

template< typename Tk, typename Tv >
void ObjectMap< Tk, Tv >::SetKey( int index, Tk value )
{
    mKeyTable[ index ] = value;
}

template< typename Tk, typename Tv >
void ObjectMap< Tk, Tv >::SetValue( int index, Tv value )
{
    mValueTable[ index ] = value;
}

// ==============================================
// Destructor
// ==============================================

template< typename Tk, typename Tv >
ObjectMap< Tk, Tv >::~ObjectMap()
{
    mKeyTable.clear();
    mValueTable.clear();

    mKeyTable   = nullptr;
    mValueTable = nullptr;
}

// ==============================================
// Miscellaneous
// ==============================================

template< typename Tk, typename Tv >
int ObjectMap< Tk, Tv >::Place( const Tk &item ) const
{
    // 1. Get the hash code (equivalent to item.hashCode() in Java)
    // std::hash returns size_t, which is usually 64-bit on modern systems.
    std::hash< Tk > hasher;
    const size_t    hashCode = hasher( item );

    // Ensure hash_code is treated as a 64-bit unsigned integer (uint64_t)
    size_t u64Hash = hashCode;

    // 2. Perform unsigned 64-bit multiplication
    // The result is an unsigned 64-bit integer.
    uint64_t multiplied = u64Hash * MAGIC_MULTIPLIER;

    // 3. Perform the logical (unsigned) right shift (>>> in Java)
    // In C++, the right shift operator >> on an unsigned type (uint64_t)
    // is guaranteed to be a logical (unsigned) shift.
    uint64_t shifted = multiplied >> mShift;

    // 4. Return as an int (Java's 'place' method returns int)
    // This is a truncation/cast, replicating the final (int) cast in Java.
    return static_cast< int >( shifted );
}

// ============================================================================
// ============================================================================
