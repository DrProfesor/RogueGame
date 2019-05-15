#ifndef ROGUEGAME_STRINGUTILS_H
#define ROGUEGAME_STRINGUTILS_H

#include <string>
#include <iostream>

namespace Utils
{
    void eraseSubStr(std::string & mainStr, const std::string & toErase)
    {
        // Search for the substring in string
        size_t pos = mainStr.find(toErase);
        
        if (pos != std::string::npos)
        {
            // If found then erase it from string
            mainStr.erase(pos, toErase.length());
        }
    }
}

#endif //ROGUEGAME_STRINGUTILS_H