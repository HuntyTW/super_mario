@echo off
set PATH=C:\Qt\Tools\mingw1310_64\bin;C:\Qt\6.8.0\mingw_64\bin;%PATH%
if exist build_qt_ninja\super_mario.exe (
    build_qt_ninja\super_mario.exe
) else (
    echo super_mario.exe not found in build_qt_ninja. Run build_qt.bat first!
)
