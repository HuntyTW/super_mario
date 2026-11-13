#!/usr/bin/env bash
set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "${ROOT_DIR}"

if [ "$1" = "console" ] || [ "$1" = "LinuxConsole" ]; then
    TARGET_DIR="build_linux_ninja"
    NAME="LinuxConsole"
    BUILD_ARG="console"
    shift 2>/dev/null || true
else
    TARGET_DIR="build_qt_ninja"
    NAME="Qt"
    BUILD_ARG="qt"
    if [ "$1" = "qt" ] || [ "$1" = "Qt" ]; then
        shift
    fi
fi

BINARY="${ROOT_DIR}/${TARGET_DIR}/super_mario"

if [ ! -f "${BINARY}" ]; then
    echo "Исполняемый файл ${BINARY} не найден. Запускаю сборку (${NAME})..."
    "${ROOT_DIR}/build.sh" "${BUILD_ARG}"
fi

echo "Запуск Super Mario (${NAME})..."
cd "${ROOT_DIR}/${TARGET_DIR}"
exec "./super_mario" "$@"
