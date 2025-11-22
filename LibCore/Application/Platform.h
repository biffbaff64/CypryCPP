// /////////////////////////////////////////////////////////////////////////////
//  MIT License
//
//  Copyright (c) 2024 Richard Ikin
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
// /////////////////////////////////////////////////////////////////////////////

#ifndef CYPRYCPP_PLATFORM_H
#define CYPRYCPP_PLATFORM_H

class Platform
{
public:
    enum ApplicationType
    {
        Windows,
        WindowsGl,
        WindowsGles,
        WindowsVk,
        WindowsGdk,
        WebGl,
        XBoxOne,
        XBoxSeries,
        NintendoSwitch,
        PlayStation4,
        PlayStation5,
        Android,
        Ios,
        MacOs,

        DefaultType = WindowsGl,
    };

    enum ApplicationFamily
    {
        Unknown,
        Mobile,  // Android, IOS
        Desktop, // WindowsGL, UWP, WebGL, Linux, MacOS
        Console, // XBox, Playstation, Nintendo

        DefaultFamily = Desktop,
    };

    [[nodiscard]] ApplicationType   GetTargetPlatform() const;
    [[nodiscard]] ApplicationFamily GetFamilyGroup() const;

    void SetTargetPlatform( ApplicationType targetPlatform );
    void SetFamilyGroup( ApplicationFamily familyGroup );

private:
    ApplicationType   mTargetPlatform = ApplicationType::DefaultType;
    ApplicationFamily mFamilyGroup    = ApplicationFamily::DefaultFamily;

    Platform()  = default;
    ~Platform() = default;
};

#endif //CYPRYCPP_PLATFORM_H
