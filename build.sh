#!/usr/bin/env bash
set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "${ROOT_DIR}"

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"
SOURCE_FOLDER="src"

build_target() {
    local target="$1"
    local game_type=""
    local build_folder=""

    if [ "${target}" = "console" ] || [ "${target}" = "LinuxConsole" ]; then
        game_type="LinuxConsole"
        build_folder="build_linux_${BUILD_SUFFIX}"
        echo "==> Сборка консольной версии (LinuxConsole) в ${build_folder}..."
    else
        game_type="Qt"
        build_folder="build_qt_${BUILD_SUFFIX}"
        echo "==> Сборка графической версии (Qt) в ${build_folder}..."
    fi

    mkdir -p "${build_folder}"
    cmake -B "${build_folder}" -S "${SOURCE_FOLDER}" -G "${BUILD_TYPE}" -DGAME_TYPE="${game_type}"
    cmake --build "${build_folder}"

    if [ "${game_type}" = "Qt" ]; then
        mkdir -p "${build_folder}/sprites"
        cp -u src/ui/qt/sprites/* "${build_folder}/sprites/" 2>/dev/null || true
    fi

    echo "==> Успешно собрано: ${build_folder}/super_mario"
}

clean_builds() {
    echo "==> Очистка каталогов сборки..."
    rm -rf build_linux_* build_qt_*
    echo "==> Готово."
}

case "$1" in
    clean)
        clean_builds
        ;;
    all)
        build_target "console"
        build_target "qt"
        ;;
    console|LinuxConsole)
        build_target "console"
        ;;
    qt|Qt|"")
        build_target "qt"
        ;;
    *)
        echo "Использование: $0 [qt|console|all|clean]"
        exit 1
        ;;
esac
