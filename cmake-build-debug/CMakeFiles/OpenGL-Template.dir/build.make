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
include CMakeFiles\OpenGL-Template.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\OpenGL-Template.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\OpenGL-Template.dir\flags.make

CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj: CMakeFiles\OpenGL-Template.dir\flags.make
CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj: ..\src\bigg\bigg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL-Template.dir/src/bigg/bigg.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj /FdCMakeFiles\OpenGL-Template.dir\ /FS -c D:\Dev\RogueGame\src\bigg\bigg.cpp
<<

CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL-Template.dir/src/bigg/bigg.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\bigg\bigg.cpp
<<

CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL-Template.dir/src/bigg/bigg.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.s /c D:\Dev\RogueGame\src\bigg\bigg.cpp
<<

CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.requires:

.PHONY : CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.requires

CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.provides: CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OpenGL-Template.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.provides.build
.PHONY : CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.provides

CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.provides.build: CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj


CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj: CMakeFiles\OpenGL-Template.dir\flags.make
CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGL-Template.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\OpenGL-Template.dir\src\main.cpp.obj /FdCMakeFiles\OpenGL-Template.dir\ /FS -c D:\Dev\RogueGame\src\main.cpp
<<

CMakeFiles\OpenGL-Template.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL-Template.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\OpenGL-Template.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\main.cpp
<<

CMakeFiles\OpenGL-Template.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL-Template.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\OpenGL-Template.dir\src\main.cpp.s /c D:\Dev\RogueGame\src\main.cpp
<<

CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.requires:

.PHONY : CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.requires

CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.provides: CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\OpenGL-Template.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.provides.build
.PHONY : CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.provides

CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.provides.build: CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj


# Object files for target OpenGL-Template
OpenGL__Template_OBJECTS = \
"CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj" \
"CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj"

# External object files for target OpenGL-Template
OpenGL__Template_EXTERNAL_OBJECTS =

OpenGL-Template.exe: CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj
OpenGL-Template.exe: CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj
OpenGL-Template.exe: CMakeFiles\OpenGL-Template.dir\build.make
OpenGL-Template.exe: deps\bgfx.cmake\bgfxd.lib
OpenGL-Template.exe: deps\imgui.lib
OpenGL-Template.exe: deps\glfw\src\glfw3.lib
OpenGL-Template.exe: deps\bgfx.cmake\bimgd.lib
OpenGL-Template.exe: deps\bgfx.cmake\astc.lib
OpenGL-Template.exe: deps\bgfx.cmake\edtaa3.lib
OpenGL-Template.exe: deps\bgfx.cmake\etc1.lib
OpenGL-Template.exe: deps\bgfx.cmake\etc2.lib
OpenGL-Template.exe: deps\bgfx.cmake\iqa.lib
OpenGL-Template.exe: deps\bgfx.cmake\squish.lib
OpenGL-Template.exe: deps\bgfx.cmake\nvtt.lib
OpenGL-Template.exe: deps\bgfx.cmake\bxd.lib
OpenGL-Template.exe: deps\bgfx.cmake\pvrtc.lib
OpenGL-Template.exe: CMakeFiles\OpenGL-Template.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Dev\RogueGame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenGL-Template.exe"
	"D:\CLion\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\OpenGL-Template.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\OpenGL-Template.dir\objects1.rsp @<<
 /out:OpenGL-Template.exe /implib:OpenGL-Template.lib /pdb:D:\Dev\RogueGame\cmake-build-debug\OpenGL-Template.pdb /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console deps\bgfx.cmake\bgfxd.lib deps\imgui.lib deps\glfw\src\glfw3.lib deps\bgfx.cmake\bimgd.lib deps\bgfx.cmake\astc.lib deps\bgfx.cmake\edtaa3.lib deps\bgfx.cmake\etc1.lib deps\bgfx.cmake\etc2.lib deps\bgfx.cmake\iqa.lib deps\bgfx.cmake\squish.lib deps\bgfx.cmake\nvtt.lib deps\bgfx.cmake\bxd.lib psapi.lib deps\bgfx.cmake\pvrtc.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\OpenGL-Template.dir\build: OpenGL-Template.exe

.PHONY : CMakeFiles\OpenGL-Template.dir\build

CMakeFiles\OpenGL-Template.dir\requires: CMakeFiles\OpenGL-Template.dir\src\bigg\bigg.cpp.obj.requires
CMakeFiles\OpenGL-Template.dir\requires: CMakeFiles\OpenGL-Template.dir\src\main.cpp.obj.requires

.PHONY : CMakeFiles\OpenGL-Template.dir\requires

CMakeFiles\OpenGL-Template.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OpenGL-Template.dir\cmake_clean.cmake
.PHONY : CMakeFiles\OpenGL-Template.dir\clean

CMakeFiles\OpenGL-Template.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Dev\RogueGame D:\Dev\RogueGame D:\Dev\RogueGame\cmake-build-debug D:\Dev\RogueGame\cmake-build-debug D:\Dev\RogueGame\cmake-build-debug\CMakeFiles\OpenGL-Template.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\OpenGL-Template.dir\depend
