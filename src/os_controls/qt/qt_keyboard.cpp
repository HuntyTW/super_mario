#include "qt_keyboard.hpp"

#include <QCoreApplication>
#include <Qt>

using biv::QtKeyBoard;
using biv::UserInput;

bool QtKeyBoard::enabled = false;
bool QtKeyBoard::left_pressed = false;
bool QtKeyBoard::right_pressed = false;
bool QtKeyBoard::jump_pressed = false;
bool QtKeyBoard::exit_pressed = false;

QtKeyBoard::QtKeyBoard() {
	enabled = true;
	left_pressed = false;
	right_pressed = false;
	jump_pressed = false;
	exit_pressed = false;
}

UserInput QtKeyBoard::get_user_input() {
	QCoreApplication::processEvents();

	if (!enabled) {
		return UserInput::NO_INPUT;
	}

	if (exit_pressed) {
		return UserInput::EXIT;
	}
	if (jump_pressed) {
		return UserInput::MARIO_JUMP;
	}
	// 'A' / Left: смещает карту вправо (Марио движется влево)
	if (left_pressed) {
		return UserInput::MAP_RIGHT;
	}
	// 'D' / Right: смещает карту влево (Марио движется вправо)
	if (right_pressed) {
		return UserInput::MAP_LEFT;
	}

	return UserInput::NO_INPUT;
}

void QtKeyBoard::on() {
	enabled = true;
}

void QtKeyBoard::off() {
	enabled = false;
	left_pressed = false;
	right_pressed = false;
	jump_pressed = false;
	exit_pressed = false;
}

void QtKeyBoard::handle_key_press(int key) {
	if (key == Qt::Key_A || key == Qt::Key_Left) {
		left_pressed = true;
	} else if (key == Qt::Key_D || key == Qt::Key_Right) {
		right_pressed = true;
	} else if (key == Qt::Key_Space || key == Qt::Key_W || key == Qt::Key_Up) {
		jump_pressed = true;
	} else if (key == Qt::Key_Q || key == Qt::Key_Escape) {
		exit_pressed = true;
	}
}

void QtKeyBoard::handle_key_release(int key) {
	if (key == Qt::Key_A || key == Qt::Key_Left) {
		left_pressed = false;
	} else if (key == Qt::Key_D || key == Qt::Key_Right) {
		right_pressed = false;
	} else if (key == Qt::Key_Space || key == Qt::Key_W || key == Qt::Key_Up) {
		jump_pressed = false;
	} else if (key == Qt::Key_Q || key == Qt::Key_Escape) {
		exit_pressed = false;
	}
}

void QtKeyBoard::request_exit() {
	exit_pressed = true;
}
