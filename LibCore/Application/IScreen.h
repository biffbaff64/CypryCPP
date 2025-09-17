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

#ifndef CYPRYCPP_ISCREEN_H
#define CYPRYCPP_ISCREEN_H

/**
 * Represents one of many application screens, such as a main menu,
 * a settings menu, the game screen and so on.
 */
class IScreen
{
public:
    /**
    * Called when this screen becomes the current screen for
    * a {@link Game}.
    */
    void Show();

    /**
    * Called when the screen should update itself.
    * @param delta The time in seconds since the last update.
    */
    void Update( float delta );

    /**
    * Called when the screen should render itself.
    * @param delta The time in seconds since the last render.
    */
    void Render( float delta );

    /**
    * Called when the Application is resized. This can happen at any point during
    * a non-paused state but will never happen before a call to create().
    */
    void Resize( int width, int height );

    /**
    * Called when the Application is paused, usually when it's not active or visible
    * on-screen. An Application is also paused before it is destroyed.
    */
    void Pause();

    /**
    * Called when the Application is resumed from a paused state, usually when
    * it regains focus.
    */
    void Resume();

    /**
    * Called when this screen is no longer the current screen for a {@link Game}.
    */
    void Hide();

    /**
    * Called when this screen should release all resources.
    */
    void Close();
};

#endif //CYPRYCPP_ISCREEN_H