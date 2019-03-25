//
// Created by jwvan on 2019-03-09.
//
#include "Logger.h"


ImGuiAl::Log _Log;

void Logger::Init()
{
    static const char* actions[] = { NULL };
    _Log.Init(0, actions);
    _Log.SetLabel( ImGuiAl::Log::kDebug, "Debug" );
    _Log.SetLabel( ImGuiAl::Log::kInfo, "Info" );
    _Log.SetLabel( ImGuiAl::Log::kWarn, "Warn" );
    _Log.SetLabel( ImGuiAl::Log::kError, "Error" );
    _Log.SetCumulativeLabel( "Cumulative" );
    _Log.SetFilterHeaderLabel( "Filters" );
    _Log.SetFilterLabel( "Filter (inc,-exc)" );
}

void Logger::Log(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    _Log.Info(format, args);
    va_end(args);
}

void Logger::LogWarn(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    _Log.Warn(format, args);
    va_end(args);
}

void Logger::LogError(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    _Log.Error(format, args);
    va_end(args);
}

ImGuiAl::Log Logger::GetLogObj() {
    return _Log;
}