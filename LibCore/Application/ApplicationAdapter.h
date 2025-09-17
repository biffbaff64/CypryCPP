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

#ifndef CYPRYCPP_APPLICATIONADAPTER_H
#define CYPRYCPP_APPLICATIONADAPTER_H
#include "Platform.h"

/// <summary>
/// Convenience implementation of a basic Application Listener.
/// Derive from this and only override what you need.
/// </summary>
class ApplicationAdapter
{
public:
    ApplicationAdapter();
    virtual ~ApplicationAdapter();

    /// <summary>
    /// Called when the Application is first created
    /// or when it is re-created after being destroyed.
    /// </summary>
    void Create();

    /// <summary>
    /// Called when the Application should update itself.
    /// </summary>
    void Update();

    /// <summary>
    /// Called when the Application should draw itself.
    /// </summary>
    void Render();

    /// <summary>
    /// Called when the Application is paused, usually when it's not active
    /// or not visible on-screen.
    /// An Application is also paused before it is destroyed.
    /// </summary>
    void Pause();

    /// <summary>
    /// Called when the Application is resumed from a paused state, usually
    /// when it regains focus.
    /// </summary>
    void Resume();

    /// <summary>
    /// Called when the Application is resized. This can happen at any point
    /// during a non-paused state but will never happen before a call to
    /// <see cref="Create"/>
    /// </summary>
	/// <param name="width"> The new width in pixels </param>
	/// <param name="height"> The new height in pixels. </param>
    void Resize( int width, int height );

    /// <summary>
    /// Gets the <see cref="Platform::ApplicationType"/> for thia app.
    /// </summary>
    [[nodiscard]] Platform::ApplicationType GetAppType() const;

private:
    Platform::ApplicationType m_appType;
    bool                      m_isDisposed = false;
};

#endif //CYPRYCPP_APPLICATIONADAPTER_H
