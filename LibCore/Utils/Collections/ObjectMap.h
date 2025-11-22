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

template< typename Tk, typename Tv >
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
    /// <param name="initialCapacity"></param>
    /// <param name="loadFactor"></param>
    /// <param name="debug"></param>
    explicit ObjectMap( int   initialCapacity = DEFAULT_CAPACITY,
                        float loadFactor      = DEFAULT_LOAD_FACTOR,
                        bool  debug           = false );

    /// <summary>
    ///
    /// </summary>
    /// <param name="otherMap"></param>
    ObjectMap( const ObjectMap &otherMap );

    // ------------------------------------------

    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <param name="initialCapacity"></param>
    /// <param name="loadFactor"></param>
    /// <returns></returns>
    [[nodiscard]] int TableSize( int initialCapacity, float loadFactor );

    // ------------------------------------------

    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <param name="initialCapacity"></param>
    void AllocateTables( int initialCapacity );

    // ------------------------------------------
    // ------------------------------------------

    // ------------------------------------------
    // Getters
    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    [[nodiscard]] int GetSize() const;

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    [[nodiscard]] bool GetAllocateIterators() const;

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    Tk GetKey( int index );

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    Tv GetValue( int index );

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    Tk *GetKeys();

    /// <summary>
    ///
    /// </summary>
    /// <returns></returns>
    Tv *GetValues();

    // ------------------------------------------
    // Setters
    // ------------------------------------------

    /// <summary>
    ///
    /// </summary>
    /// <param name="value"></param>
    void SetSize( int value );

    /// <summary>
    ///
    /// </summary>
    /// <param name="value"></param>
    void SetAllocateIterators( bool value );

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <param name="value"></param>
    void SetKey( int index, Tk value );

    /// <summary>
    ///
    /// </summary>
    /// <param name="index"></param>
    /// <param name="value"></param>
    void SetValue( int index, Tv value );

    // ------------------------------------------
    // Destructor
    // ------------------------------------------

    /// <summary>
    /// Destructor.
    /// </summary>
    ~ObjectMap();

protected:
    int                       Place( const Tk &item ) const;
    int                       LocateKey( const Tk &key ) const;
    Tv                        Put( const Tk &key, const Tv &value );
    void                      PutAll( const ObjectMap &otherMap );
    void                      PutResize( Tk key, Tv value );
    Tv                        Get( const Tk &key ) const;
    Tv                        Get( const Tk &key, Tv defaultValue ) const;
    Tv                        Remove( const Tk &key );
    [[nodiscard]] bool        NotEmpty() const;
    [[nodiscard]] bool        IsEmpty() const;
    void                      Shrink( int maximumCapacity );
    void                      Clear( int maximumCapacity );
    void                      Clear();
    bool                      ContainsValue( const Tv &value, bool identity ) const;
    bool                      ContainsKey( const Tk &key ) const;
    Tk                        FindKey( const Tk &value, bool identity ) const;
    void                      EnsureCapacity( int additionalCapacity );
    void                      Resize( int additionalCapacity );
    [[nodiscard]] bool        Equals( const ObjectMap &otherMap ) const;
    [[nodiscard]] bool        EqualsIdentity( const ObjectMap &otherMap ) const;
    [[nodiscard]] std::string ToString() const;
    [[nodiscard]] std::string ToString( std::string separator ) const;
    [[nodiscard]] std::string ToString( std::string separator, bool braces ) const;

private:
    static constexpr int      DEFAULT_CAPACITY    = 51;
    static constexpr float    DEFAULT_LOAD_FACTOR = 0.8f;
    static constexpr uint64_t MAGIC_MULTIPLIER    = 0x9E3779B97F4A7C15ULL;

    int mSize      = 0;
    int mShift     = 0;
    int mMask      = 0;
    int mThreshold = 0;
    int mCapacity  = 0;

    float mLoadFactor = 0;

    bool mAllocateIterators = false;

    std::vector< Tk > mKeyTable;
    std::vector< Tv > mValueTable;
};

#endif //CYPRYCPP_OBJECTMAP_H
