#include "qt_game_window.hpp"

#include <QCoreApplication>
#include <QKeyEvent>
#include <QPainter>
#include <iostream>

#include "qt_keyboard.hpp"
#include "qt_mario.hpp"

using biv::QtGameWindow;
using biv::QtUIObject;

QtGameWindow::QtGameWindow(const int height, const int width, QWidget* parent)
	: QWidget(parent), map_height(height), map_width(width) {
	setWindowTitle("Super Mario Bros");

	// Расчет начального размера окна:
	// 30 строк по высоте, 40 колонок видимой ширины, клетка 24x24 px
	const int cell_size = 24;
	const int visible_cols = 40;
	resize(visible_cols * cell_size, map_height * cell_size);
	setMinimumSize(visible_cols * 16, map_height * 16);

	// Фокус для клавиатуры
	setFocusPolicy(Qt::StrongFocus);
	setAttribute(Qt::WA_OpaquePaintEvent);
}

void QtGameWindow::set_objects(const std::vector<QtUIObject*>& objects) {
	objs = objects;
}

void QtGameWindow::render_frame() {
	repaint();
	QCoreApplication::processEvents();
}

void QtGameWindow::paintEvent(QPaintEvent* /*event*/) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, false);

	int cell_h = height() / map_height;
	if (cell_h < 1) {
		cell_h = 1;
	}
	int cell_w = cell_h; // Квадратные клетки для правильных пропорций спрайтов

	// Находим координаты Марио для центрирования камеры
	int mario_x = 39;
	for (QtUIObject* obj : objs) {
		if (dynamic_cast<QtMario*>(obj) != nullptr) {
			mario_x = obj->get_left();
			break;
		}
	}

	// Марио находится примерно на 1/3 экрана (12 клеток от левого края камеры)
	int camera_x = mario_x - 12;

	// 1. Небо классического синего цвета NES Super Mario (#5c94fc)
	painter.fillRect(rect(), QColor(92, 148, 252));

	// 2. Вода внизу карты (последние 3 строки)
	int water_top_cell = map_height - 3;
	int water_y = water_top_cell * cell_h;
	if (water_y < height()) {
		QRect water_rect(0, water_y, width(), height() - water_y);
		painter.fillRect(water_rect, QColor(32, 56, 236));

		// Линия белых гребней волн по верху воды
		painter.setPen(QColor(255, 255, 255, 200));
		for (int x = 0; x < width(); x += 8) {
			painter.drawLine(x, water_y, x + 4, water_y);
		}
	}

	// 3. Отрисовка всех игровых объектов
	for (QtUIObject* obj : objs) {
		if (obj != nullptr) {
			obj->draw(painter, cell_w, cell_h, camera_x);
		}
	}
}

void QtGameWindow::keyPressEvent(QKeyEvent* event) {
	if (!event->isAutoRepeat()) {
		QtKeyBoard::handle_key_press(event->key());
	}
	QWidget::keyPressEvent(event);
}

void QtGameWindow::keyReleaseEvent(QKeyEvent* event) {
	if (!event->isAutoRepeat()) {
		QtKeyBoard::handle_key_release(event->key());
	}
	QWidget::keyReleaseEvent(event);
}

void QtGameWindow::closeEvent(QCloseEvent* event) {
	QtKeyBoard::request_exit();
	QWidget::closeEvent(event);
}
