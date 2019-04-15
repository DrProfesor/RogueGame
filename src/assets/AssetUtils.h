//
// Created by Jake on 3/21/19.
//

#ifndef ROGUEGAME_UTILS_H
#define ROGUEGAME_UTILS_H

#include <bx/pixelformat.h>
#include <bgfx/bgfx.h>
#include <bimg/bimg.h>
#include <bx/bx.h>
#include <bx/math.h>
#include <bx/readerwriter.h>
#include <bx/string.h>
#include <bx/file.h>

#include <fstream>
#include <string>

namespace Utils {

    static bx::FileReaderI* fileReader = NULL;
    static bx::FileWriterI* fileWriter = NULL;

    void Init();

    bx::AllocatorI* GetDefaultAllocator();

    const bgfx::Memory* LoadMemory(const char* filePath);
    bgfx::ProgramHandle LoadShader(std::string vertPath, std::string fragPath);
    bgfx::TextureHandle LoadTexture(const char* filePath,
            uint32_t _flags = 0x0,
            uint8_t _skip = 0,
            bgfx::TextureInfo* _info = NULL,
            bimg::Orientation::Enum* _orientation = NULL);
};


#endif //ROGUEGAME_UTILS_H
