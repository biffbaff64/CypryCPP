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

    static std::vector< Color > GetPredefinedColors();

    void DebugPrint() const;

    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color CLEAR;
    static const Color WHITE;
    static const Color BLACK;
    static const Color GRAY;
    static const Color LIGHTGRAY;
    static const Color DARKGRAY;
    static const Color SLATE;
    static const Color NAVY;
    static const Color ROYAL;
    static const Color SKY;
    static const Color CYAN;
    static const Color TEAL;
    static const Color CHARTREUSE;
    static const Color LIME;
    static const Color FOREST;
    static const Color OLIVE;
    static const Color YELLOW;
    static const Color GOLD;
    static const Color GOLDENROD;
    static const Color ORANGE;
    static const Color BROWN;
    static const Color TAN;
    static const Color FIREBRICK;
    static const Color SCARLET;
    static const Color CORAL;
    static const Color SALMON;
    static const Color PINK;
    static const Color MAGENTA;
    static const Color PURPLE;
    static const Color VIOLET;
    static const Color MAROON;

private:
};

#endif //CYPRYCPP_COLOR_H
