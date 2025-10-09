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

#ifndef CYPRYCPP_OBJECTMAP_H
#define CYPRYCPP_OBJECTMAP_H
#include <cstdint>
#include <vector>

template< typename TK, typename TV >
class ObjectMap
{
public:
    /// <summary>
    /// Default constructor. This will instantiate a new ObjectMap object
    /// using parameter values of DEFAULT_CAPACITY and DEFAULT_LOAD_FACTOR.
    /// </summary>
    ObjectMap();

    /// <summary>
    ///
    /// </summary>
    /// <param name="initialCapacity"></param>
    explicit ObjectMap( int initialCapacity = DEFAULT_CAPACITY );

    /// <summary>
    ///
    /// </summary>
    /// <param name="initial_capacity"></param>
    /// <param name="load_factor"></param>
    /// <param name="debug"></param>
    explicit ObjectMap( int   initial_capacity = DEFAULT_CAPACITY,
                        float load_factor      = DEFAULT_LOAD_FACTOR,
                        bool  debug            = false );

    /// <summary>
    ///
    /// </summary>
    /// <param name="other_map"></param>
    ObjectMap( const ObjectMap &other_map );

    // ------------------------------------------

    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <param name="initial_capacity"></param>
    /// <param name="load_factor"></param>
    /// <returns></returns>
    [[nodiscard]] int table_size( int initial_capacity, float load_factor );

    // ------------------------------------------

    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <param name="initial_capacity"></param>
    void allocate_tables( int initial_capacity );

    // ------------------------------------------
    // ------------------------------------------

    // ------------------------------------------
    // Getters
    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    [[nodiscard]] int get_size() const;

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    [[nodiscard]] bool get_allocate_iterators() const;

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    TK get_key( int index );

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    TV get_value( int index );

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    TK *get_keys();

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    TV *get_values();

    // ------------------------------------------
    // Setters
    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <param name="value"></param>
    void set_size( int value );

    /// <summary>
    ///
    /// </summary>
    /// <param name="value"></param>
    void set_allocate_iterators( bool value );

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <param name="value"></param>
    void set_key( int index, TK value );

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <param name="value"></param>
    void set_value( int index, TV value );

    // ------------------------------------------
    // Destructor
    // ------------------------------------------

    /// <summary>
    /// Destructor.
    /// </summary>
    ~ObjectMap();

protected:
    int  place( const TK &item ) const;
    int  locate_key( const TK &key ) const;
    TV   put( const TK &key, const TV &value );
    void put_all( const ObjectMap &other_map );
    void put_resize( TK key, TV value );
    TV   get( const TK &key ) const;
    TV   get( const TK &key, TV default_value ) const;
    TV remove( const TK &key );
    [[nodiscard]] bool not_empty() const;
    [[nodiscard]] bool is_empty() const;
    void shrink( int maximum_capacity );
    void clear( int maximum_capacity );
    void clear();
    bool contains_value( const TV &value, bool identity ) const;
    bool contains_key( const TK &key ) const;
    TK find_key( const TK &value, bool identity ) const;
    void ensure_capacity( int additional_capacity );
    void resize( int additional_capacity );
    bool equals( const ObjectMap &other_map ) const;
    bool equals_identity( const ObjectMap &other_map ) const;
    std::string to_string() const;
    std::string to_string( std::string separator ) const;
    std::string to_string( std::string separator, bool braces ) const;



private:
    static constexpr int      DEFAULT_CAPACITY    = 51;
    static constexpr float    DEFAULT_LOAD_FACTOR = 0.8f;
    static constexpr uint64_t MAGIC_MULTIPLIER    = 0x9E3779B97F4A7C15ULL;

    int m_size      = 0;
    int m_shift     = 0;
    int m_mask      = 0;
    int m_threshold = 0;
    int m_capacity  = 0;

    float m_load_factor = 0;

    bool m_allocate_iterators = false;

    std::vector< TK > m_key_table;
    std::vector< TV > m_value_table;
};

#endif //CYPRYCPP_OBJECTMAP_H
