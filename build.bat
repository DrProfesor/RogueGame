#"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64

set generate_code=FALSE
set build=TRUE
set run=FALSE

if /i "%1" EQU "-gen" set generate_code=TRUE
if /i "%2" EQU "-gen" set generate_code=TRUE
if /i "%3" EQU "-gen" set generate_code=TRUE

if /i "%1" EQU "-run" set run=TRUE
if /i "%2" EQU "-run" set run=TRUE
if /i "%3" EQU "-run" set run=TRUE

if /i "%1" EQU "-no-build" set build=FALSE
if /i "%2" EQU "-no-build" set build=FALSE
if /i "%3" EQU "-no-build" set build=FALSE

if %generate_code% == TRUE (
	cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - NMake Makefiles" D:\Dev\RogueGame
)

if %build% == TRUE (
	cmake --build cmake-build-debug --target RogueGame
)

if %run% == TRUE (
	START cmake-build-debug\RogueGame.exe
)