@echo off
chcp 65001 >nul

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja
set SOURCE_FOLDER=src

if "%1"=="clean" (
    echo Очистка каталогов сборки...
    if exist build_windows_%BUILD_SUFFIX% rmdir /s /q build_windows_%BUILD_SUFFIX%
    if exist build_qt_%BUILD_SUFFIX% rmdir /s /q build_qt_%BUILD_SUFFIX%
    echo Готово.
    exit /b 0
)

if "%1"=="console" (
    set GAME_TYPE=WindowsConsole
    set BUILD_FOLDER=build_windows_%BUILD_SUFFIX%
    set PATH=C:\Users\user\Desktop\mingw64\bin;%PATH%
) else if "%1"=="WindowsConsole" (
    set GAME_TYPE=WindowsConsole
    set BUILD_FOLDER=build_windows_%BUILD_SUFFIX%
    set PATH=C:\Users\user\Desktop\mingw64\bin;%PATH%
) else (
    set GAME_TYPE=Qt
    set BUILD_FOLDER=build_qt_%BUILD_SUFFIX%
    set PATH=C:\Qt\Tools\mingw1310_64\bin;C:\Qt\6.8.0\mingw_64\bin;%PATH%
)

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% -DGAME_TYPE=%GAME_TYPE% -DCMAKE_PREFIX_PATH="C:/Qt/6.8.0/mingw_64" ..\%SOURCE_FOLDER%
cmake --build .

if "%GAME_TYPE%"=="Qt" (
    if not exist sprites mkdir sprites
    copy /y ..\src\ui\qt\sprites\*.* sprites\ >nul
    if exist "C:\Qt\6.8.0\mingw_64\bin\windeployqt.exe" (
        "C:\Qt\6.8.0\mingw_64\bin\windeployqt.exe" --no-translations --no-opengl-sw super_mario.exe
    )
)

cd ..
