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

#ifndef CYPRYCPP_IAPPLICATION_H
#define CYPRYCPP_IAPPLICATION_H

#include "Platform.h"
#include "../Utils/IClipboard.h"
#include "../Utils/IRunnable.h"
#include "ILifecycleListener.h"
#include "../Utils/Logging/IPreferences.h"

class IApplication
{
public:
    Platform::ApplicationType AppType;

    /**
     * Provides functionality for clipboard operations, allowing interaction with
     * system clipboard to copy and paste data.
     */
    IClipboard Clipboard;

    /**
     * Returns the Android API level on Android, the major OS version on iOS (5, 6, 7, ..),
     * or 0 on the desktop.
     */
    int GetVersion();

    /**
     * Returns the {@link IPreferences} instance of this Application. It can be
     * used to store application settings across runs.
     * @param name the name of the preferences, must be usable as a file name.
     * @returns The preferences.
     */
    IPreferences GetPreferences( char *name );

    /**
     * Adds a new {@link ILifecycleListener} to the application. This can be
     * used by extensions to hook into the lifecycle more easily.
     * The <see cref="IApplicationListener" /> methods are sufficient for application
     * level development.
     */
    void AddLifecycleListener( ILifecycleListener listener );

    /**
     * Removes the specified <see cref="ILifecycleListener" />
     */
    void RemoveLifecycleListener( ILifecycleListener listener );

    /**
     * Posts a <see cref="IRunnable" /> to the event queue.
     */
    void PostRunnable( IRunnable runnable );

    /**
     * Schedule an exit from the application. On android, this will cause a call to
     * <see cref="IApplicationListener.Pause()" /> and <see cref="IDisposable.Dispose()" />
     * some time in the future.
     * <para>
     * It will not immediately finish your application.
     * </para>
     * <para>
     * On iOS this should be avoided in production as it breaks Apples guidelines
     * </para>
     */
    void Exit();

    /**
     * Cleanup everything before shutdown.
     */
    void Cleanup();

private:
    IApplication()  = default;
    ~IApplication() = default;
};

#endif //CYPRYCPP_IAPPLICATION_H
