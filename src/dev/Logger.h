//
// Created by jwvan on 2019-03-09.
//

#ifndef PROGRAMVIEWER_LOGGER_H
#define PROGRAMVIEWER_LOGGER_H

#include <cstdarg>
#include <imguial_log.h>

struct Logger {
    static void Init();
    static void Log(const char* format, ...);
    static void LogWarn(const char* format, ...);
    static void LogError(const char* format, ...);

    static ImGuiAl::Log GetLogObj();

};


#endif //PROGRAMVIEWER_LOGGER_H