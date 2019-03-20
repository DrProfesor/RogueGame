cmake_minimum_required( VERSION 3.0 )

set(APP_TARGET RogueGame)
project(${APP_TARGET})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ASSIMP_BUILD_STATIC_LIB ON)

add_subdirectory( deps )
add_subdirectory(deps/assimp)
include_directories(deps/assimp/include)

#include( deps/bgfx.cmake/cmake/util/ConfigureDebugging.cmake )
#add_library( app STATIC src/app.cpp src/bigg_assets.h src/bigg_imgui.hpp src/bigg_shaders.hpp include/app.hpp )

file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.h src/*.hpp)

if (APPLE)
    find_library(corefoundation_lib CoreFoundation)
    find_library(cfnetwork_lib CFNetwork)

    set(frameworks
            ${cfnetwork_lib}
            ${corefoundation_lib})
endif (APPLE)


add_executable( ${APP_TARGET} ${SRC_FILES} )


if (APPLE)
    target_link_libraries(${APP_TARGET} ${frameworks})
endif (APPLE)

target_link_libraries( ${APP_TARGET} bgfx imgui glfw glm )
target_include_directories( ${APP_TARGET} PUBLIC include )