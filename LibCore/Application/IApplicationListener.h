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

#ifndef CYPRYCPP_IAPPLICATIONLISTENER_H
#define CYPRYCPP_IAPPLICATIONLISTENER_H

class IApplicationListener
{
public:
    /**
    * Called when the {@link IApplication} is first created.
    */
    void Create();

    /**
    * Called when the {@link IApplication} is resized. This can
    * happen at any point during a non-paused state but will never happen
    * before a call to {@link Create}.
    * @param width The new width in pixels.
    * @param height The new height in pixels.
    */
    void Resize( int width, int height );

    /**
    * Called when the {@link IApplication} should update itself.
    */
    void Update();

    /**
    * Called when the {@link IApplication} should draw itself.
    */
    void Render();

    /**
    * Called when the {@link IApplication} is paused, usually when
    * it's not active or visible on-screen. An Application is also
    * paused before it is destroyed.
    */
    void Pause();

    /**
    * Called when the {@link IApplication} is resumed from a paused state,
    * usually when it regains focus.
    */
    void Resume();

private:
    IApplicationListener() = default;
    ~IApplicationListener() = default;
};

#endif //CYPRYCPP_IAPPLICATIONLISTENER_H