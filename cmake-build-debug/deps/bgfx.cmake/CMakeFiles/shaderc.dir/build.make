# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Dev\RogueGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Dev\RogueGame\cmake-build-debug

# Include any dependencies generated for this target.
include deps\bgfx.cmake\CMakeFiles\shaderc.dir\depend.make

# Include the progress variables for this target.
include deps\bgfx.cmake\CMakeFiles\shaderc.dir\progress.make

# Include the compile flags for this target's objects.
include deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj: ..\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.s /c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj


deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj: ..\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_glsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_glsl.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_glsl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_glsl.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_glsl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_glsl.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.s /c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_glsl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj


deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj: ..\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_hlsl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_hlsl.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_hlsl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_hlsl.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_hlsl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_hlsl.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.s /c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_hlsl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj


deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj: ..\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_pssl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_pssl.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_pssl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_pssl.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_pssl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_pssl.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.s /c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_pssl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj


deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj: ..\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_spirv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_spirv.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_spirv.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_spirv.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_spirv.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/bgfx/tools/shaderc/shaderc_spirv.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.s /c D:\Dev\RogueGame\deps\bgfx.cmake\bgfx\tools\shaderc\shaderc_spirv.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj


deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj: deps\bgfx.cmake\generated\vertexdecl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/generated/vertexdecl.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\generated\vertexdecl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/generated/vertexdecl.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\generated\vertexdecl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/generated/vertexdecl.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\generated\vertexdecl.cpp.s /c D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\generated\vertexdecl.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj


deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj: deps\bgfx.cmake\CMakeFiles\shaderc.dir\flags.make
deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj: deps\bgfx.cmake\generated\shader_spirv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object deps/bgfx.cmake/CMakeFiles/shaderc.dir/generated/shader_spirv.cpp.obj"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj /FdCMakeFiles\shaderc.dir\ /FS -c D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\generated\shader_spirv.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaderc.dir/generated/shader_spirv.cpp.i"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\generated\shader_spirv.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaderc.dir/generated/shader_spirv.cpp.s"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\shaderc.dir\generated\shader_spirv.cpp.s /c D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\generated\shader_spirv.cpp
<<
	cd D:\Dev\RogueGame\cmake-build-debug

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.requires:

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.provides: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.requires
	$(MAKE) -f deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make /nologo -$(MAKEFLAGS) deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.provides.build
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.provides

deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.provides.build: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj


# Object files for target shaderc
shaderc_OBJECTS = \
"CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj" \
"CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj" \
"CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj" \
"CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj" \
"CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj" \
"CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj" \
"CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj"

# External object files for target shaderc
shaderc_EXTERNAL_OBJECTS =

deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\build.make
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\bxd.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\bimgd.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\fcpp.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\glsl-optimizer.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\glslang.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\astc.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\edtaa3.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\etc1.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\etc2.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\iqa.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\squish.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\nvtt.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\bxd.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\pvrtc.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\glcpp.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\mesa.lib
deps\bgfx.cmake\shaderc.exe: deps\bgfx.cmake\CMakeFiles\shaderc.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable shaderc.exe"
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	"D:\CLion\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\shaderc.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\shaderc.dir\objects1.rsp @<<
 /out:shaderc.exe /implib:shaderc.lib /pdb:D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\shaderc.pdb /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console bxd.lib bimgd.lib fcpp.lib glsl-optimizer.lib glslang.lib astc.lib edtaa3.lib etc1.lib etc2.lib iqa.lib squish.lib nvtt.lib bxd.lib psapi.lib pvrtc.lib glcpp.lib mesa.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd D:\Dev\RogueGame\cmake-build-debug

# Rule to build all files generated by this target.
deps\bgfx.cmake\CMakeFiles\shaderc.dir\build: deps\bgfx.cmake\shaderc.exe

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\build

deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc.cpp.obj.requires
deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_glsl.cpp.obj.requires
deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_hlsl.cpp.obj.requires
deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_pssl.cpp.obj.requires
deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\bgfx\tools\shaderc\shaderc_spirv.cpp.obj.requires
deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\vertexdecl.cpp.obj.requires
deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires: deps\bgfx.cmake\CMakeFiles\shaderc.dir\generated\shader_spirv.cpp.obj.requires

.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\requires

deps\bgfx.cmake\CMakeFiles\shaderc.dir\clean:
	cd D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake
	$(CMAKE_COMMAND) -P CMakeFiles\shaderc.dir\cmake_clean.cmake
	cd D:\Dev\RogueGame\cmake-build-debug
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\clean

deps\bgfx.cmake\CMakeFiles\shaderc.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Dev\RogueGame D:\Dev\RogueGame\deps\bgfx.cmake D:\Dev\RogueGame\cmake-build-debug D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake D:\Dev\RogueGame\cmake-build-debug\deps\bgfx.cmake\CMakeFiles\shaderc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : deps\bgfx.cmake\CMakeFiles\shaderc.dir\depend
