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

#ifndef CYPRYCPP_LOGGER_H
#define CYPRYCPP_LOGGER_H

#include <iostream>
#include <string>

class Logger
{
public:
    static void Initialise( int log_level, bool enable_write_to_file, char *filename );

    static void Debug( const char *message, bool boxed_debug = false );
    static void Debug( std::string message, bool boxed_debug = false );

    static void DebugConditional( const char *message, bool condition );
    static void DebugConditional( std::string message, bool condition );

    static void Error( const char *message );
    static void Error( std::string message );

    static void CheckPoint();
    static void Divider( char ch = '=', int length = 80 );
    static void DividerConditional( bool condition, char ch = '=', int length = 80 );

    static void OpenDebugFile( const char *filename, bool delete_existing = true );
    static void OpenDebugFile( std::string filename, bool delete_existing = true );

    static void WriteToDebugFile( const char *message );
    static void WriteToDebugFile( std::string message );

    static void CloseDebugFile();

    static void EnableDebugLogging();
    static void DisableDebugLogging();
    static void EnableErrorLogging();
    static void DisableErrorLogging();
    static void EnableCheckPointLogging();
    static void DisableCheckPointLogging();
    static void EnableWriteToFile();
    static void DisableWriteToFile();
    static void SetLogLevel( int level );

private:
    struct CallerId
    {
        const char *filename;
        int         line;
        const char *function;
    };

    Logger()  = default;
    ~Logger() = default;

    static char *   CreateMessage( const char *tag, CallerId cid, const char *format_string );
    static CallerId MakeCallerId();
    static char *   GetTimestampInfo();
    static void     GetCallerInfo( CallerId &cid );

    static bool IsEnabled( int level );
};

// Define the DEBUG macro only if the preprocessor symbol DEBUG is defined
#ifdef DEBUG

// Macro for the boxed version (forces boxedDebug to true)
#define DEBUG_BOXED(message) \
Logger::debug((message), true, __FILE__, __func__, __LINE__)

// Macro for the standard version (forces boxedDebug to false)
// We use a variadic macro to allow an optional second argument (although we only support a single message here)
#define DEBUG_MSG(message) \
Logger::debug((message), false, __FILE__, __func__, __LINE__)

#elif

// If DEBUG is NOT defined (e.g., in Release builds), the macros do nothing.
// This is the C++ equivalent of the [Conditional("DEBUG")] attribute.
#define DEBUG_BOXED(message) (void)0
#define DEBUG_MSG(message) (void)0

#endif // DEBUG

#endif //CYPRYCPP_LOGGER_H
