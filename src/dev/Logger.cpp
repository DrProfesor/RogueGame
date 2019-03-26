//
// Created by jwvan on 2019-03-09.
//
#include <string>
#include "Logger.h"

AppLog _Log;

void Logger::Init()
{
}

void Logger::Log(const char* format, ...)
{
    va_list args;
    auto _fmt = (std::string(format) + "\n").c_str();
    va_start(args, format);
    _Log.AddLog(_fmt, args);
    va_end(args);
}

void Logger::LogWarn(const char* format, ...)
{
    va_list args;
    auto _fmt = (std::string(format) + "\n").c_str();
    va_start(args, format);
    _Log.AddLog(_fmt, args);
    va_end(args);
}

void Logger::LogError(const char* format, ...)
{
    va_list args;
    auto _fmt = (std::string(format) + "\n").c_str();
    va_start(args, format);
    _Log.AddLog(_fmt, args);
    va_end(args);
}

AppLog Logger::GetLogObj() {
    return _Log;
}