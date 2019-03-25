//
// Created by Jake on 3/21/19.
//

#include "Utils.h"

namespace Utils {
    bx::AllocatorI* g_allocator = Utils::GetDefaultAllocator();

    typedef bx::StringT<&g_allocator> String;

    static String s_currentDir;

    class FileReader : public bx::FileReader
    {
        typedef bx::FileReader super;

    public:
        bool open(const bx::FilePath& _filePath, bx::Error* _err) override
        {
            String filePath(s_currentDir);
            filePath.append(_filePath.get());
            return super::open(filePath.getPtr(), _err);
        }
    };

    class FileWriter : public bx::FileWriter
    {
        typedef bx::FileWriter super;

    public:
        bool open(const bx::FilePath& _filePath, bool _append, bx::Error* _err) override
        {
            String filePath(s_currentDir);
            filePath.append(_filePath.get());
            return super::open(filePath.getPtr(), _append, _err);
        }
    };
}

void Utils::Init()
{
    fileReader = BX_NEW(Utils::GetDefaultAllocator(), FileReader);
    fileWriter = BX_NEW(Utils::GetDefaultAllocator(), FileWriter);
}

bx::AllocatorI* Utils::GetDefaultAllocator()
{
    BX_PRAGMA_DIAGNOSTIC_PUSH();
    BX_PRAGMA_DIAGNOSTIC_IGNORED_MSVC(4459); // warning C4459: declaration of 's_allocator' hides global declaration
    BX_PRAGMA_DIAGNOSTIC_IGNORED_CLANG_GCC("-Wshadow");
    static bx::DefaultAllocator s_allocator;
    return &s_allocator;
    BX_PRAGMA_DIAGNOSTIC_POP();
}

bgfx::ShaderHandle loadShader( const char* shader )
{
    return bgfx::createShader( Utils::LoadMemory( shader ) );
}

const bgfx::Memory* Utils::LoadMemory(const char* filePath)
{
    std::ifstream file( filePath, std::ios::binary | std::ios::ate );
    std::streamsize size = file.tellg();
    file.seekg( 0, std::ios::beg );
    const bgfx::Memory* mem = bgfx::alloc( uint32_t( size + 1 ) );
    if ( file.read( ( char* )mem->data, size ) )
    {
        mem->data[ mem->size - 1 ] = '\0';
        return mem;
    }
    return nullptr;
}

bgfx::ProgramHandle Utils::LoadShader(std::string name)
{
    bgfx::ShaderHandle vs = loadShader( ("vs_" + name + ".sc").c_str() );
    bgfx::ShaderHandle fs = loadShader( ("fs_" + name + ".sc").c_str() );
    return bgfx::createProgram( vs, fs, true );
}

static void imageReleaseCb(void* _ptr, void* _userData)
{
    bimg::ImageContainer* imageContainer = (bimg::ImageContainer*)_userData;
    bimg::imageFree(imageContainer);
}

void* load(bx::FileReaderI* _reader, bx::AllocatorI* _allocator, const char* _filePath, uint32_t* _size)
{
    if (bx::open(_reader, _filePath))
    {
        uint32_t size = (uint32_t)bx::getSize(_reader);
        void* data = BX_ALLOC(_allocator, size);
        bx::read(_reader, data, size);
        bx::close(_reader);
        if (NULL != _size)
        {
            *_size = size;
        }
        return data;
    }
    if (NULL != _size)
    {
        *_size = 0;
    }

    return NULL;
}

void unload(void* _ptr)
{
    BX_FREE(Utils::GetDefaultAllocator(), _ptr);
}

bgfx::TextureHandle Utils::LoadTexture(const char* filePath, uint32_t _flags, uint8_t _skip, bgfx::TextureInfo* _info, bimg::Orientation::Enum* _orientation)
{
    BX_UNUSED(_skip);
    bgfx::TextureHandle handle = BGFX_INVALID_HANDLE;

    uint32_t size;
    void* data = load(fileReader, Utils::GetDefaultAllocator(), filePath, &size);
    if (NULL != data)
    {
        bimg::ImageContainer* imageContainer;
        if (bimg::imageParse(*imageContainer, data, size))
        {
            if (NULL != _orientation)
            {
                *_orientation = imageContainer->m_orientation;
            }

            const bgfx::Memory* mem = bgfx::makeRef(
                    imageContainer->m_data
                    , imageContainer->m_size
                    , imageReleaseCb
                    , imageContainer
            );
            unload(data);

            if (imageContainer->m_cubeMap)
            {
                handle = bgfx::createTextureCube(
                        uint16_t(imageContainer->m_width)
                        , 1 < imageContainer->m_numMips
                        , imageContainer->m_numLayers
                        , bgfx::TextureFormat::Enum(imageContainer->m_format)
                        , _flags
                        , mem
                );
            }
            else if (1 < imageContainer->m_depth)
            {
                handle = bgfx::createTexture3D(
                        uint16_t(imageContainer->m_width)
                        , uint16_t(imageContainer->m_height)
                        , uint16_t(imageContainer->m_depth)
                        , 1 < imageContainer->m_numMips
                        , bgfx::TextureFormat::Enum(imageContainer->m_format)
                        , _flags
                        , mem
                );
            }
            else if (bgfx::isTextureValid(0, false, imageContainer->m_numLayers, bgfx::TextureFormat::Enum(imageContainer->m_format), _flags) )
            {
                handle = bgfx::createTexture2D(
                        uint16_t(imageContainer->m_width)
                        , uint16_t(imageContainer->m_height)
                        , 1 < imageContainer->m_numMips
                        , imageContainer->m_numLayers
                        , bgfx::TextureFormat::Enum(imageContainer->m_format)
                        , _flags
                        , mem
                );
            }

            if (bgfx::isValid(handle) )
            {
                bgfx::setName(handle, filePath);
            }

            if (NULL != _info)
            {
                bgfx::calcTextureSize(
                        *_info
                        , uint16_t(imageContainer->m_width)
                        , uint16_t(imageContainer->m_height)
                        , uint16_t(imageContainer->m_depth)
                        , imageContainer->m_cubeMap
                        , 1 < imageContainer->m_numMips
                        , imageContainer->m_numLayers
                        , bgfx::TextureFormat::Enum(imageContainer->m_format)
                );
            }
        }
    }

    return handle;
}