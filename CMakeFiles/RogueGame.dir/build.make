# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = D:\Dev\Cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Dev\Cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Dev\RogueGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Dev\RogueGame

# Include any dependencies generated for this target.
include CMakeFiles\RogueGame.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\RogueGame.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\RogueGame.dir\flags.make

CMakeFiles\RogueGame.dir\src\app\Application.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\app\Application.cpp.obj: src\app\Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RogueGame.dir/src/app/Application.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\app\Application.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\app\Application.cpp
<<

CMakeFiles\RogueGame.dir\src\app\Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/app/Application.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\app\Application.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\app\Application.cpp
<<

CMakeFiles\RogueGame.dir\src\app\Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/app/Application.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\app\Application.cpp.s /c D:\Dev\RogueGame\src\app\Application.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.obj: src\assets\AssetUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RogueGame.dir/src/assets/AssetUtils.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\assets\AssetUtils.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/assets/AssetUtils.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\assets\AssetUtils.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/assets/AssetUtils.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.s /c D:\Dev\RogueGame\src\assets\AssetUtils.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.obj: src\assets\Assets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RogueGame.dir/src/assets/Assets.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\assets\Assets.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\assets\Assets.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/assets/Assets.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\assets\Assets.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/assets/Assets.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\assets\Assets.cpp.s /c D:\Dev\RogueGame\src\assets\Assets.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.obj: src\assets\tinyfiledialogs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RogueGame.dir/src/assets/tinyfiledialogs.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\assets\tinyfiledialogs.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/assets/tinyfiledialogs.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\assets\tinyfiledialogs.cpp
<<

CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/assets/tinyfiledialogs.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.s /c D:\Dev\RogueGame\src\assets\tinyfiledialogs.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.obj: src\editor\Editor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RogueGame.dir/src/editor/Editor.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\editor\Editor.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\editor\Editor.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/editor/Editor.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\editor\Editor.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/editor/Editor.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\editor\Editor.cpp.s /c D:\Dev\RogueGame\src\editor\Editor.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.obj: src\editor\FileViewer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RogueGame.dir/src/editor/FileViewer.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\editor\FileViewer.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/editor/FileViewer.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\editor\FileViewer.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/editor/FileViewer.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.s /c D:\Dev\RogueGame\src\editor\FileViewer.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.obj: src\editor\ImGuizmo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RogueGame.dir/src/editor/ImGuizmo.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\editor\ImGuizmo.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/editor/ImGuizmo.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\editor\ImGuizmo.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/editor/ImGuizmo.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.s /c D:\Dev\RogueGame\src\editor\ImGuizmo.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.obj: src\editor\Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RogueGame.dir/src/editor/Logger.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\editor\Logger.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\editor\Logger.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/editor/Logger.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\editor\Logger.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/editor/Logger.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\editor\Logger.cpp.s /c D:\Dev\RogueGame\src\editor\Logger.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.obj: src\editor\SceneWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RogueGame.dir/src/editor/SceneWindow.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\editor\SceneWindow.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/editor/SceneWindow.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\editor\SceneWindow.cpp
<<

CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/editor/SceneWindow.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.s /c D:\Dev\RogueGame\src\editor\SceneWindow.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.obj: src\entity\Entities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/RogueGame.dir/src/entity/Entities.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\entity\Entities.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\entity\Entities.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/entity/Entities.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\entity\Entities.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/entity/Entities.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\entity\Entities.cpp.s /c D:\Dev\RogueGame\src\entity\Entities.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.obj: src\entity\Generated.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/RogueGame.dir/src/entity/Generated.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\entity\Generated.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\entity\Generated.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/entity/Generated.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\entity\Generated.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/entity/Generated.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\entity\Generated.cpp.s /c D:\Dev\RogueGame\src\entity\Generated.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.obj: src\entity\Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/RogueGame.dir/src/entity/Scene.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\entity\Scene.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\entity\Scene.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/entity/Scene.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\entity\Scene.cpp
<<

CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/entity/Scene.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\entity\Scene.cpp.s /c D:\Dev\RogueGame\src\entity\Scene.cpp
<<

CMakeFiles\RogueGame.dir\src\input\Input.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\input\Input.cpp.obj: src\input\Input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/RogueGame.dir/src/input/Input.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\input\Input.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\input\Input.cpp
<<

CMakeFiles\RogueGame.dir\src\input\Input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/input/Input.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\input\Input.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\input\Input.cpp
<<

CMakeFiles\RogueGame.dir\src\input\Input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/input/Input.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\input\Input.cpp.s /c D:\Dev\RogueGame\src\input\Input.cpp
<<

CMakeFiles\RogueGame.dir\src\main.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\main.cpp.obj: src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/RogueGame.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\main.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\main.cpp
<<

CMakeFiles\RogueGame.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\main.cpp
<<

CMakeFiles\RogueGame.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\main.cpp.s /c D:\Dev\RogueGame\src\main.cpp
<<

CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.obj: src\physics\Physics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/RogueGame.dir/src/physics/Physics.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\physics\Physics.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\physics\Physics.cpp
<<

CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/physics/Physics.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\physics\Physics.cpp
<<

CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/physics/Physics.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\physics\Physics.cpp.s /c D:\Dev\RogueGame\src\physics\Physics.cpp
<<

CMakeFiles\RogueGame.dir\src\physics\Time.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\physics\Time.cpp.obj: src\physics\Time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/RogueGame.dir/src/physics/Time.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\physics\Time.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\physics\Time.cpp
<<

CMakeFiles\RogueGame.dir\src\physics\Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/physics/Time.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\physics\Time.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\physics\Time.cpp
<<

CMakeFiles\RogueGame.dir\src\physics\Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/physics/Time.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\physics\Time.cpp.s /c D:\Dev\RogueGame\src\physics\Time.cpp
<<

CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.obj: CMakeFiles\RogueGame.dir\flags.make
CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.obj: src\rendering\Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/RogueGame.dir/src/rendering/Renderer.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.obj /FdCMakeFiles\RogueGame.dir\ /FS -c D:\Dev\RogueGame\src\rendering\Renderer.cpp
<<

CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RogueGame.dir/src/rendering/Renderer.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe > CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Dev\RogueGame\src\rendering\Renderer.cpp
<<

CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RogueGame.dir/src/rendering/Renderer.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.s /c D:\Dev\RogueGame\src\rendering\Renderer.cpp
<<

# Object files for target RogueGame
RogueGame_OBJECTS = \
"CMakeFiles\RogueGame.dir\src\app\Application.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\input\Input.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\main.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\physics\Time.cpp.obj" \
"CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.obj"

# External object files for target RogueGame
RogueGame_EXTERNAL_OBJECTS =

RogueGame.exe: CMakeFiles\RogueGame.dir\src\app\Application.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\assets\AssetUtils.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\assets\Assets.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\assets\tinyfiledialogs.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\editor\Editor.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\editor\FileViewer.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\editor\ImGuizmo.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\editor\Logger.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\editor\SceneWindow.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\entity\Entities.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\entity\Generated.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\entity\Scene.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\input\Input.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\main.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\physics\Physics.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\physics\Time.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\src\rendering\Renderer.cpp.obj
RogueGame.exe: CMakeFiles\RogueGame.dir\build.make
RogueGame.exe: lib\assimp-vc140-mtd.lib
RogueGame.exe: deps\bgfx.cmake\bgfx\.build\projects\cmake\brtshaderc\brtshadercd.lib
RogueGame.exe: deps\bgfx.cmake\bgfxdd.lib
RogueGame.exe: deps\imguid.lib
RogueGame.exe: deps\glfw\src\glfw3d.lib
RogueGame.exe: lib\zlibstaticd.lib
RogueGame.exe: lib\IrrXMLd.lib
RogueGame.exe: deps\bgfx.cmake\bimgdd.lib
RogueGame.exe: deps\bgfx.cmake\astcd.lib
RogueGame.exe: deps\bgfx.cmake\edtaa3d.lib
RogueGame.exe: deps\bgfx.cmake\etc1d.lib
RogueGame.exe: deps\bgfx.cmake\etc2d.lib
RogueGame.exe: deps\bgfx.cmake\iqad.lib
RogueGame.exe: deps\bgfx.cmake\squishd.lib
RogueGame.exe: deps\bgfx.cmake\nvttd.lib
RogueGame.exe: deps\bgfx.cmake\bxdd.lib
RogueGame.exe: deps\bgfx.cmake\pvrtcd.lib
RogueGame.exe: CMakeFiles\RogueGame.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Dev\RogueGame\CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable RogueGame.exe"
	D:\Dev\Cmake\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\RogueGame.dir --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\RogueGame.dir\objects1.rsp @<<
 /out:RogueGame.exe /implib:RogueGame.lib /pdb:D:\Dev\RogueGame\RogueGame.pdb /version:0.0  /subsystem:console lib\assimp-vc140-mtd.lib deps\bgfx.cmake\bgfx\.build\projects\cmake\brtshaderc\brtshadercd.lib deps\bgfx.cmake\bgfxdd.lib deps\imguid.lib deps\glfw\src\glfw3d.lib lib\zlibstaticd.lib lib\IrrXMLd.lib deps\bgfx.cmake\bimgdd.lib deps\bgfx.cmake\astcd.lib deps\bgfx.cmake\edtaa3d.lib deps\bgfx.cmake\etc1d.lib deps\bgfx.cmake\etc2d.lib deps\bgfx.cmake\iqad.lib deps\bgfx.cmake\squishd.lib deps\bgfx.cmake\nvttd.lib deps\bgfx.cmake\bxdd.lib psapi.lib deps\bgfx.cmake\pvrtcd.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\RogueGame.dir\build: RogueGame.exe

.PHONY : CMakeFiles\RogueGame.dir\build

CMakeFiles\RogueGame.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RogueGame.dir\cmake_clean.cmake
.PHONY : CMakeFiles\RogueGame.dir\clean

CMakeFiles\RogueGame.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\Dev\RogueGame D:\Dev\RogueGame D:\Dev\RogueGame D:\Dev\RogueGame D:\Dev\RogueGame\CMakeFiles\RogueGame.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\RogueGame.dir\depend

