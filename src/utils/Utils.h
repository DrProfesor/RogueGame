//
// Created by Jake on 3/19/19.
//

#ifndef ROGUEGAME_UTILS_H
#define ROGUEGAME_UTILS_H

#include <vector>
#include <fstream>

static std::vector<char> ReadAllBytes(char const* filename)
{
    using namespace std;
    ifstream ifs(filename, ios::binary|ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    std::vector<char>  result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);

    return result;
}

#endif //ROGUEGAME_UTILS_H
