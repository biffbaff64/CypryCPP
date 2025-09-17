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

#include "Color.h"

#include <algorithm>
#include <iostream>

// ============================================================================

const Color Color::Red( 1.0f, 0.0f, 0.0f, 1.0f );
const Color Color::Green( 0.0f, 1.0f, 0.0f, 1.0f );
const Color Color::Blue( 0.0f, 0.0f, 1.0f, 1.0f );
const Color Color::Clear( 0.0f, 0.0f, 0.0f, 0.0f );
const Color Color::White( 1.0f, 1.0f, 1.0f, 1.0f );
const Color Color::Black( 0.0f, 0.0f, 0.0f, 1.0f );
const Color Color::Gray( 0.5f, 0.5f, 0.5f, 1.0f );
const Color Color::LightGray( 0.75f, 0.75f, 0.75f, 1.0f );
const Color Color::DarkGray( 0.25f, 0.25f, 0.25f, 1.0f );
const Color Color::Slate( 0.439f, 0.502f, 0.565f, 1.0f );
const Color Color::Navy( 0.0f, 0.0f, 0.502f, 1.0f );
const Color Color::Royal( 0.255f, 0.0f, 0.502f, 1.0f );
const Color Color::Sky( 0.529f, 0.808f, 0.922f, 1.0f );
const Color Color::Cyan( 0.0f, 1.0f, 1.0f, 1.0f );
const Color Color::Teal( 0.0f, 0.502f, 0.502f, 1.0f );
const Color Color::Chartreuse( 0.498f, 1.0f, 0.0f, 1.0f );
const Color Color::Lime( 0.0f, 1.0f, 0.0f, 1.0f );
const Color Color::Forest( 0.133f, 0.545f, 0.133f, 1.0f );
const Color Color::Olive( 0.502f, 0.502f, 0.0f, 1.0f );
const Color Color::Yellow( 1.0f, 1.0f, 0.0f, 1.0f );
const Color Color::Gold( 1.0f, 0.843f, 0.0f, 1.0f );
const Color Color::Goldenrod( 0.855f, 0.647f, 0.125f, 1.0f );
const Color Color::Orange( 1.0f, 0.647f, 0.0f, 1.0f );
const Color Color::Brown( 0.647f, 0.165f, 0.165f, 1.0f );
const Color Color::Tan( 0.824f, 0.706f, 0.549f, 1.0f );
const Color Color::Firebrick( 0.698f, 0.133f, 0.133f, 1.0f );
const Color Color::Scarlet( 1.0f, 0.271f, 0.271f, 1.0f );
const Color Color::Coral( 1.0f, 0.498f, 0.314f, 1.0f );
const Color Color::Salmon( 0.980f, 0.502f, 0.447f, 1.0f );
const Color Color::Pink( 1.0f, 0.753f, 0.796f, 1.0f );
const Color Color::Magenta( 1.0f, 0.0f, 1.0f, 1.0f );
const Color Color::Purple( 0.502f, 0.0f, 0.502f, 1.0f );
const Color Color::Violet( 0.933f, 0.510f, 0.933f, 1.0f );
const Color Color::Maroon( 0.502f, 0.0f, 0.0f, 1.0f );

// ============================================================================

// Default constructor
Color::Color() : r( 0.0f ), g( 0.0f ), b( 0.0f ), a( 1.0f )
{
}

// Parameterized constructor
Color::Color( float r, float g, float b, float a ) : r( r ), g( g ), b( b ), a( a )
{
}

Color Color::operator+( const Color &other ) const
{
    return
    {
        std::min( r + other.r, 1.0f ),
        std::min( g + other.g, 1.0f ),
        std::min( b + other.b, 1.0f ),
        std::min( a + other.a, 1.0f )
    };
}

Color Color::operator*( float scalar ) const
{
    return {
        r * scalar,
        g * scalar,
        b * scalar,
        a * scalar
    };
}

void Color::Clamp()
{
    r = r < 0.0f ? 0.0f : r > 1.0f ? 1.0f : r;
    g = g < 0.0f ? 0.0f : g > 1.0f ? 1.0f : g;
    b = b < 0.0f ? 0.0f : b > 1.0f ? 1.0f : b;
    a = a < 0.0f ? 0.0f : a > 1.0f ? 1.0f : a;
}

std::vector< Color > Color::getPredefinedColors()
{
    return {
        Color::Red,
        Color::Green,
        Color::Blue,
        Color::Clear,
        Color::White,
        Color::Black,
        Color::Gray,
        Color::LightGray,
        Color::DarkGray,
        Color::Slate,
        Color::Navy,
        Color::Royal,
        Color::Sky,
        Color::Cyan,
        Color::Teal,
        Color::Chartreuse,
        Color::Lime,
        Color::Forest,
        Color::Olive,
        Color::Yellow,
        Color::Gold,
        Color::Goldenrod,
        Color::Orange,
        Color::Brown,
        Color::Tan,
        Color::Firebrick,
        Color::Scarlet,
        Color::Coral,
        Color::Salmon,
        Color::Pink,
        Color::Magenta,
        Color::Purple,
        Color::Violet,
        Color::Maroon,
    };
}

void Color::debug_print() const
{
    std::cout << "RGBA(" << r << ", " << g << ", " << b << ", " << a << ")" << std::endl;
}
