@echo off
chcp 65001 >nul

set ROOT_DIR=%~dp0
cd /d "%ROOT_DIR%"

if "%1"=="console" (
    set TARGET=build_windows_ninja
    set EXE=super_mario.exe
    set BUILD_ARG=console
) else if "%1"=="WindowsConsole" (
    set TARGET=build_windows_ninja
    set EXE=super_mario.exe
    set BUILD_ARG=console
) else (
    set TARGET=build_qt_ninja
    set EXE=super_mario.exe
    set BUILD_ARG=qt
    set PATH=C:\Qt\Tools\mingw1310_64\bin;C:\Qt\6.8.0\mingw_64\bin;%PATH%
)

if not exist "%TARGET%\%EXE%" (
    echo Исполняемый файл %TARGET%\%EXE% не найден. Запускаю сборку...
    call build.bat %BUILD_ARG%
)

cd "%TARGET%"
"%EXE%"
cd /d "%ROOT_DIR%"
