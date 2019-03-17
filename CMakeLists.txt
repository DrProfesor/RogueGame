cmake_minimum_required( VERSION 3.0 )

set(APP_TARGET RogueGame)
project(${APP_TARGET})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory( deps )

#include( deps/bgfx.cmake/cmake/util/ConfigureDebugging.cmake )
#add_library( app STATIC src/app.cpp src/bigg_assets.h src/bigg_imgui.hpp src/bigg_shaders.hpp include/app.hpp )

file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.h src/*.hpp)

add_executable( ${APP_TARGET} ${SRC_FILES} )

target_link_libraries( ${APP_TARGET} PUBLIC bgfx imgui glfw glm )
target_include_directories( ${APP_TARGET} PUBLIC include )

option( BIGG_EXAMPLES "Build examples." OFF )
if( BIGG_EXAMPLES )
	add_subdirectory( examples )
endif()

option( BIGG_ASSET_GEN "Generate binary assets." OFF )
if( BIGG_ASSET_GEN )
	add_subdirectory( assets/gen )
endif()
