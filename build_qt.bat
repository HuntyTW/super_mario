@echo off

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set PATH=C:\Qt\Tools\mingw1310_64\bin;C:\Qt\6.8.0\mingw_64\bin;%PATH%

set BUILD_FOLDER=build_qt_%BUILD_SUFFIX%
set SOURCE_FOLDER=src

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

set GAME_TYPE=Qt

cmake -G %BUILD_TYPE% -DGAME_TYPE=%GAME_TYPE% -DCMAKE_PREFIX_PATH="C:/Qt/6.8.0/mingw_64" ..\%SOURCE_FOLDER%
cmake --build .

if not exist sprites mkdir sprites
copy /y ..\src\ui\qt\sprites\*.* sprites\ >nul

if exist "C:\Qt\6.8.0\mingw_64\bin\windeployqt.exe" (
    "C:\Qt\6.8.0\mingw_64\bin\windeployqt.exe" --no-translations --no-opengl-sw super_mario.exe
)

cd ..
