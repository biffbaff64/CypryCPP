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

template< typename TK, typename TV >
ObjectMap< TK, TV >::ObjectMap() : ObjectMap( DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR )
{
}

template< typename TK, typename TV >
ObjectMap< TK, TV >::ObjectMap( int initialCapacity )
    : ObjectMap( initialCapacity, DEFAULT_LOAD_FACTOR )
{
}

template< typename TK, typename TV >
ObjectMap< TK, TV >::ObjectMap( int initial_capacity, float load_factor, bool debug )
{
    if ( m_load_factor <= 0.0f || m_load_factor >= 1.0f )
    {
        throw std::runtime_error( std::format( "loadFactor must be > 0 and < 1: {}", load_factor ) );
    }

    m_load_factor = load_factor;

    int tabl_size = table_size( initial_capacity, load_factor );

    m_threshold = static_cast< int >( static_cast< float >( tabl_size ) * load_factor );
    m_mask      = tabl_size - 1;
    m_shift     = std::countl_zero( static_cast< unsigned int >( m_mask ) );

    allocate_tables( tabl_size );

    if ( debug )
    {
        Logger::debug( std::format( "initialCapacity: {}", initial_capacity ) );
        Logger::debug( std::format( "initialCapacity * loadFactor: {}", ( float )initial_capacity * load_factor ) );
        Logger::debug( std::format( "KeyTable.Size: {}", std::size( get_keys() ) ) );
        Logger::debug( std::format( "ValueTable.Size: {}", std::size( get_values() ) ) );
    }
}

template< typename TK, typename TV >
ObjectMap< TK, TV >::ObjectMap( const ObjectMap &other_map )
    : ObjectMap( static_cast< int >( other_map.m_key_table.m_length * other_map.m_load_factor ), // Initial capacity
                 other_map.m_load_factor,                                                        // Load factor
                 false )
{
    m_key_table   = other_map.m_key_table;
    m_value_table = other_map.m_value_table;

    m_size = other_map.m_size;
}

template< typename TK, typename TV >
int ObjectMap< TK, TV >::table_size( int initial_capacity, float load_factor )
{
    return MathUtils::next_power_of_two( std::max( 2, ( int )std::ceil( ( float )initial_capacity / load_factor ) ) );
}

template< typename TK, typename TV >
void ObjectMap< TK, TV >::allocate_tables( int initial_capacity )
{
    if ( initial_capacity <= 0 )
    {
        throw std::invalid_argument( "size must be > 0" );
    }

    // initialise the vectors to hold 'initial_capacity' number of elements.
    m_key_table.reserve( initial_capacity );
    m_value_table.reserve( initial_capacity );

    m_capacity = initial_capacity;
    m_size     = 0;
}

// ==============================================
// Getters
// ==============================================

template< typename TK, typename TV >
int ObjectMap< TK, TV >::get_size() const
{
    return m_size;
}

template< typename TK, typename TV >
bool ObjectMap< TK, TV >::get_allocate_iterators() const
{
    return m_allocate_iterators;
}

template< typename TK, typename TV >
TK ObjectMap< TK, TV >::get_key( int index )
{
    return m_key_table[ index ];
}

template< typename TK, typename TV >
TV ObjectMap< TK, TV >::get_value( int index )
{
    return m_value_table[ index ];
}

template< typename TK, typename TV >
TK *ObjectMap< TK, TV >::get_keys()
{
    return m_key_table;
}

template< typename TK, typename TV >
TV *ObjectMap< TK, TV >::get_values()
{
    return m_value_table;
}

// ==============================================
// Setters
// ==============================================

template< typename TK, typename TV >
void ObjectMap< TK, TV >::set_size( int value )
{
    m_size = value;
}

template< typename TK, typename TV >
void ObjectMap< TK, TV >::set_allocate_iterators( bool value )
{
    m_allocate_iterators = value;
}

template< typename TK, typename TV >
void ObjectMap< TK, TV >::set_key( int index, TK value )
{
    m_key_table[ index ] = value;
}

template< typename TK, typename TV >
void ObjectMap< TK, TV >::set_value( int index, TV value )
{
    m_value_table[ index ] = value;
}

// ==============================================
// Destructor
// ==============================================

template< typename TK, typename TV >
ObjectMap< TK, TV >::~ObjectMap()
{
    m_key_table.clear();
    m_value_table.clear();

    m_key_table   = nullptr;
    m_value_table = nullptr;
}

// ==============================================
// Miscellaneous
// ==============================================

template< typename TK, typename TV >
int ObjectMap< TK, TV >::Place( const TK &item ) const
{
    // 1. Get the hash code (equivalent to item.hashCode() in Java)
    // std::hash returns size_t, which is usually 64-bit on modern systems.
    std::hash< TK > hasher;
    size_t          hash_code = hasher( item );

    // Ensure hash_code is treated as a 64-bit unsigned integer (uint64_t)
    auto u64_hash = hash_code;

    // 2. Perform unsigned 64-bit multiplication
    // The result is an unsigned 64-bit integer.
    uint64_t multiplied = u64_hash * MAGIC_MULTIPLIER;

    // 3. Perform the logical (unsigned) right shift (>>> in Java)
    // In C++, the right shift operator >> on an unsigned type (uint64_t)
    // is guaranteed to be a logical (unsigned) shift.
    uint64_t shifted = multiplied >> m_shift;

    // 4. Return as an int (Java's 'place' method returns int)
    // This is a truncation/cast, replicating the final (int) cast in Java.
    return static_cast< int >( shifted );
}

// ============================================================================
// ============================================================================
