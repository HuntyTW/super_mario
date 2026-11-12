#!/usr/bin/env bash

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"
SOURCE_FOLDER="src"

if [ "$1" = "console" ] || [ "$1" = "LinuxConsole" ]; then
    GAME_TYPE="LinuxConsole"
    BUILD_FOLDER="build_linux_${BUILD_SUFFIX}"
else
    GAME_TYPE="Qt"
    BUILD_FOLDER="build_qt_${BUILD_SUFFIX}"
fi

mkdir -p "${BUILD_FOLDER}"
cd "${BUILD_FOLDER}"

export GAME_TYPE

cmake -G "${BUILD_TYPE}" -DGAME_TYPE="${GAME_TYPE}" "../${SOURCE_FOLDER}"
cmake --build .

cd ..
