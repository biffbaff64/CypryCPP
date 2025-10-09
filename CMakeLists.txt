cmake_minimum_required(VERSION 4.0)
project(CypryCPP)

set(CMAKE_CXX_STANDARD 26)

add_library(CypryCPP SHARED library.cpp
        LibCore/Graphics/OpenGL/IGL.h
        LibCore/Application/Platform.cpp
        LibCore/Application/Platform.h
        LibCore/Application/ApplicationAdapter.cpp
        LibCore/Application/ApplicationAdapter.h
        LibCore/Application/Engine.cpp
        LibCore/Application/Engine.h
        LibCore/Application/ApplicationConfiguration.cpp
        LibCore/Application/ApplicationConfiguration.h
        LibCore/Application/Game.h
        LibCore/Application/ScreenAdapter.h
        LibCore/Application/GameTime.cpp
        LibCore/Application/GameTime.h
        LibCore/Application/LibraryVersion.cpp
        LibCore/Application/LibraryVersion.h
        LibCore/Application/ILifeCycleListener.h
        LibCore/Application/IApplication.h
        LibCore/Application/IApplicationListener.h
        LibCore/Application/IScreen.h
        LibCore/Utils/Logging/IPreferences.h
        LibCore/Utils/IClipboard.h
        LibCore/Utils/IRunnable.h
        LibCore/Files/PathTypes.cpp
        LibCore/Files/PathTypes.h
        LibCore/Graphics/Color.cpp
        LibCore/Graphics/Color.h
        LibCore/Graphics/GraphicsDevice.cpp
        LibCore/Graphics/GraphicsDevice.h
        LibCore/Graphics/ICursor.cpp
        LibCore/Graphics/ICursor.h
        LibCore/Graphics/OpenGL/GlVersion.cpp
        LibCore/Graphics/OpenGL/GlVersion.h
        LibCore/Utils/Collections/ObjectMap.cpp
        LibCore/Utils/Collections/ObjectMap.h
        LibCore/Utils/Logging/Logger.cpp
        LibCore/Utils/Logging/Logger.h
        LibCore/Maths/MathUtils.cpp
        LibCore/Maths/MathUtils.h)
