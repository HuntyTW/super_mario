#include "windows_control_settings.hpp"

#include <windows.h>

using biv::WindowsControlSettings;

WindowsControlSettings::WindowsControlSettings(const int height, const int width)
	: height(height), width(width) {}

void WindowsControlSettings::init() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	// Карта шириной `width` и высотой `height` символов рисуется построчно
	// без переноса строк (см. ConsoleGameMap::show()), поэтому, если окно
	// консоли уже, чем карта, Windows сама переносит строки автопереносом,
	// и строки карты "съезжают" друг относительно друга. Чтобы этого не
	// происходило, сперва уменьшаем окно до минимума, затем увеличиваем
	// буфер экрана до нужного размера, и только потом растягиваем окно
	// до размеров буфера (именно в таком порядке, иначе Windows не даст
	// установить размер окна больше текущего буфера, и наоборот).
	SMALL_RECT minimal_window_rect = {0, 0, 1, 1};
	SetConsoleWindowInfo(handle, TRUE, &minimal_window_rect);

	COORD buffer_size;
	buffer_size.X = static_cast<SHORT>(width);
	buffer_size.Y = static_cast<SHORT>(height);
	SetConsoleScreenBufferSize(handle, buffer_size);

	SMALL_RECT window_rect;
	window_rect.Left = 0;
	window_rect.Top = 0;
	window_rect.Right = static_cast<SHORT>(width - 1);
	window_rect.Bottom = static_cast<SHORT>(height - 1);
	SetConsoleWindowInfo(handle, TRUE, &window_rect);
}

void WindowsControlSettings::set_cursor_start_position() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
