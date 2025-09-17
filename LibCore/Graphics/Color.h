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

#ifndef CYPRYCPP_COLOR_H
#define CYPRYCPP_COLOR_H
#include <vector>

class Color
{
public:
    float r, g, b, a;

    // Constructors
    Color();
    Color( float r, float g, float b, float a = 1.0f );

    // Overloaded Operators
    Color operator+( const Color &other ) const;
    Color operator*( float scalar ) const;

    void Clamp();

    static std::vector< Color > getPredefinedColors();

    void debug_print() const;

    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Clear;
    static const Color White;
    static const Color Black;
    static const Color Gray;
    static const Color LightGray;
    static const Color DarkGray;
    static const Color Slate;
    static const Color Navy;
    static const Color Royal;
    static const Color Sky;
    static const Color Cyan;
    static const Color Teal;
    static const Color Chartreuse;
    static const Color Lime;
    static const Color Forest;
    static const Color Olive;
    static const Color Yellow;
    static const Color Gold;
    static const Color Goldenrod;
    static const Color Orange;
    static const Color Brown;
    static const Color Tan;
    static const Color Firebrick;
    static const Color Scarlet;
    static const Color Coral;
    static const Color Salmon;
    static const Color Pink;
    static const Color Magenta;
    static const Color Purple;
    static const Color Violet;
    static const Color Maroon;

private:
};

#endif //CYPRYCPP_COLOR_H
