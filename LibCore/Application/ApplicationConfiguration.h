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

#ifndef CYPRYCPP_APPLICATIONCONFIGURATION_H
#define CYPRYCPP_APPLICATIONCONFIGURATION_H

#include <climits>
#include <vector>

#include "../Files/PathTypes.h"
#include "../Graphics/Color.h"
#include "../Graphics/GraphicsDevice.h"

class ApplicationConfiguration
{
public:
    ApplicationConfiguration()          = default;
    virtual ~ApplicationConfiguration() = default;

    enum GLEmulationType
    {
        AngleGles20,
        GL20,
        GL30,
        GL31,
        GL32,
    }

    // ========================================================================
    // General Application Configuration
    // ========================================================================

    const char *DEFAULT_PREFS_DIR = ".prefs/";

    BackendType     GraphicsBackend      = BackendType.OpenGL;
    HdpiMode        HdpiMode             = HdpiMode.Logical;
    GLEmulationType GLEmulation          = GLEmulationType::GL20;
    PathTypes       PreferencesFileType  = PathTypes::External;
    char *          PreferencesDirectory = nullptr;

    bool DisableAudio                   = false;
    int  AudioDeviceSimultaneousSources = 16;
    int  AudioDeviceBufferSize          = 512;
    int  AudioDeviceBufferCount         = 9;
    bool Debug                          = false;
    bool TransparentFramebuffer         = false;
    int  Depth                          = 16;
    int  Stencil                        = 0;
    int  Samples                        = 0;
    int  IdleFPS                        = 60;
    int  ForegroundFPS                  = 0;
    int  GLContextMajorVersion          = 0;
    int  GLContextMinorVersion          = 0;
    int  GLContextRevision              = 0;
    int  Red                            = 8;
    int  Green                          = 8;
    int  Blue                           = 8;
    int  Alpha                          = 8;
    bool PauseWhenLostFocus             = true;
    bool PauseWhenMinimized             = true;
    bool GLProfilingEnabled             = true;

    /// <summary>
    /// The maximum number of threads to use for network requests.
    /// Default is <see cref="int.MaxValue" />.
    /// </summary>
    int MaxNetThreads = INT_MAX;

    // ========================================================================

    int WindowX         = DEFAULT_WINDOW_X;
    int WindowY         = DEFAULT_WINDOW_Y;
    int WindowWidth     = DEFAULT_WINDOW_WIDTH;
    int WindowHeight    = DEFAULT_WINDOW_HEIGHT;
    int WindowMinWidth  = DEFAULT_WINDOW_MIN_WIDTH;
    int WindowMinHeight = DEFAULT_WINDOW_MIN_HEIGHT;
    int WindowMaxWidth  = DEFAULT_WINDOW_MAX_WIDTH;
    int WindowMaxHeight = DEFAULT_WINDOW_MAX_HEIGHT;

    PathTypes             WindowIconFileType;
    std::vector< char * > WindowIconPaths;

    // ========================================================================

    /// <summary>
    /// Whether the window will be visible on creation. (default true)
    /// </summary>
    bool InitialVisibility = true;

    /// <summary>
    /// Sets whether to use VSync.
    /// <para>
    /// This setting can be changed anytime at runtime via <see cref="GraphicsDevice.SetVSync(bool)" />.
    /// </para>
    /// <para>
    /// For multi-window applications, only one (the main) window should enable vsync. Otherwise,
    /// every window will wait for the vertical blank on swap individually, effectively cutting
    /// the frame rate to (refreshRate / numberOfWindows).
    /// </para>
    /// </summary>
    bool VSyncEnabled = true;

    /// <summary>
    /// Whether the windowed mode window is resizable (default true)
    /// </summary>
    bool WindowResizable = true;

    /// <summary>
    /// Whether the windowed mode window is decorated, i.e. displaying the title bars.
    /// (default true)
    /// </summary>
    bool WindowDecorated = true;

    /// <summary>
    /// Whether the window starts maximized. Ignored if the window is full screen.
    /// (default false)
    /// </summary>
    bool WindowMaximized = false;

    /// <summary>
    /// Whether the window should automatically iconify and restore previous video mode
    /// on input focus loss. (default false). Does nothing in windowed mode.
    /// (default false)
    /// </summary>
    bool AutoIconify = false;

    /// <summary>
    /// The initial window background color. Defaults to blue.
    /// </summary>
    Color InitialBackgroundColor = Color::Blue;

    /// <summary>
    /// Sets the window title. Defaults to empty string.
    /// </summary>
    char *Title = nullptr;

    // ========================================================================

    // ========================================================================

    /// <summary>
    /// Creates, and returns, a new ApplicationConfiguration, using settings
    /// from the supplied ApplicationConfiguration object.
    /// </summary>
    static ApplicationConfiguration Copy( ApplicationConfiguration config );

    /// <summary>
    /// Sets this ApplicationConfiguration settings, using settings from
    /// the supplied ApplicationConfiguration object.
    /// </summary>
    void Set( ApplicationConfiguration config );

    /// <summary>
    /// Sets the audio device configuration.
    /// </summary>
    /// <param name="simultaniousSources">
    /// the maximum number of sources that can be played simultaniously (default 16)
    /// </param>
    /// <param name="bufferSize">the audio device buffer size in samples (default 512)</param>
    /// <param name="bufferCount">the audio device buffer count (default 9)</param>
    void SetAudioConfig( int simultaniousSources, int bufferSize, int bufferCount );

    /// <summary>
    /// Sets which OpenGL version to use to emulate OpenGL ES. If the given major/minor version
    /// is not supported, the backend falls back to OpenGL ES 2.0 emulation through OpenGL 2.0.
    /// The default parameters for major and minor should be 3 and 2 respectively to be compatible
    /// with Mac OS X. Specifying major version 4 and minor version 2 will ensure that all OpenGL ES
    /// 3.0 features are supported. Note however that Mac OS X does only support 3.2.
    /// </summary>
    /// <param name="glVersion"> which OpenGL ES emulation version to use </param>
    /// <param name="glesMajorVersion"> OpenGL ES major version, use 3 as default </param>
    /// <param name="glesMinorVersion"> OpenGL ES minor version, use 2 as default </param>
    void SetOpenGLEmulation( GLEmulationType glVersion, int glesMajorVersion, int glesMinorVersion );

    /// <summary>
    /// Sets the bit depth of the color, depth and stencil buffer as well as multi-sampling.
    /// </summary>
    /// <param name="r"> red bits (default 8) </param>
    /// <param name="g"> green bits (default 8) </param>
    /// <param name="b"> blue bits (default 8) </param>
    /// <param name="a"> alpha bits (default 8) </param>
    /// <param name="depth"> depth bits (default 16) </param>
    /// <param name="stencil"> stencil bits (default 0) </param>
    /// <param name="samples"> MSAA samples (default 0) </param>
    void SetBackBufferConfig( int r       = 8,
                              int g       = 8,
                              int b       = 8,
                              int a       = 8,
                              int depth   = 16,
                              int stencil = 0,
                              int samples = 0 );

    /// <summary>
    /// Sets the directory where <see cref="IPreferences" /> will be stored, as well as
    /// the file type to be used to store them. Defaults to "$USER_HOME/.prefs/"
    /// and <see cref="PathTypes" />.
    /// </summary>
    void SetPreferencesConfig( char *preferencesDirectory, PathTypes preferencesFileType );

    /// <summary>
    /// Sets the correct values for <see cref="GLContextMajorVersion" /> and
    /// <see cref="GLContextMinorVersion" />.
    /// </summary>
    void SetGLContextVersion( int major, int minor );

    /// <summary>
    /// Gets the currently active display mode for the primary monitor.
    /// </summary>
    GraphicsDevice::DisplayMode GetDisplayMode();

    /// <summary>
    /// Gets the currterntly active display mode for the given monitor.
    /// </summary>
    GraphicsDevice::DisplayMode GetDisplayMode( GLFW.Monitor monitor );

    /// <summary>
    /// Return the available <see cref="GraphicsDevice.DisplayMode" />s of the primary monitor
    /// </summary>
    GraphicsDevice::DisplayMode[] GetDisplayModes();

    /// <summary>
    /// Returns a list of the available <see cref="GraphicsDevice.DisplayMode" />s of the given monitor.
    /// </summary>
    GraphicsDevice::DisplayMode [] GetDisplayModes( GLFW.Monitor monitor );

    // ========================================================================

    /// <summary>
    /// Configures the window settings based on the provided configuration.
    /// </summary>
    /// <param name="config">The window configuration to apply.</param>
    void SetWindowConfiguration( ApplicationConfiguration config );

    /// <summary>
    /// Sets the app to use windowed mode.
    /// </summary>
    /// <param name="width"> the width of the window (default 640) </param>
    /// <param name="height">the height of the window (default 480) </param>
    void SetWindowedMode( int width, int height );

    /// <summary>
    /// Sets the position of the window in windowed mode.
    /// Default -1 for both coordinates for centered on primary monitor.
    /// </summary>
    void SetWindowPosition( int x, int y );

    /// <summary>
    /// Sets minimum and maximum size limits for the window. If the window is full
    /// screen or not resizable, these limits are ignored. The default for all four
    /// parameters is -1, which means unrestricted.
    /// </summary>
    void SetWindowSizeLimits( int minWidth, int minHeight, int maxWidth, int maxHeight );

    /// <summary>
    /// Sets the icon that will be used in the window's title bar. Has no effect in
    /// macOS, which doesn't use window icons.
    /// </summary>
    /// <param name="filePath">
    /// One or more internal image paths. Must be JPEG, PNG, or BMP format. The one
    /// closest to the system's desired size will be scaled. Good sizes include 16x16,
    /// 32x32 and 48x48.
    /// </param>
    void SetWindowIcon( char* filePath );
    void SetWindowIcon( char* filePaths[] );

    /// <summary>
    /// Sets the icon that will be used in the window's title bar.Has no effect in macOS,
    /// which doesn't use window icons.
    /// </summary>
    /// <param name="fileType"> The type of file handle the paths are relative to. </param>
    /// <param name="filePath">
    /// One or more image paths, relative to the given <see cref="PathTypes" />. Must be JPEG,
    /// PNG, or BMP format. The one closest to the system's desired size will be scaled.
    /// Good sizes include 16x16, 32x32 and 48x48.
    /// </param>
    void SetWindowIcon( PathTypes fileType, char* filePath );
    void SetWindowIcon( PathTypes fileType, char* filePaths[] );

    // ========================================================================
    // Window Specific Configuration
    // ========================================================================

    const int DEFAULT_WINDOW_WIDTH      = 640;
    const int DEFAULT_WINDOW_HEIGHT     = 480;
    const int DEFAULT_WINDOW_X          = 80;
    const int DEFAULT_WINDOW_Y          = 80;
    const int DEFAULT_WINDOW_MIN_WIDTH  = 320;
    const int DEFAULT_WINDOW_MIN_HEIGHT = 240;
    const int DEFAULT_WINDOW_MAX_WIDTH  = 1280;
    const int DEFAULT_WINDOW_MAX_HEIGHT = 960;

private:
    // Nothing here
};

#endif //CYPRYCPP_APPLICATIONCONFIGURATION_H
