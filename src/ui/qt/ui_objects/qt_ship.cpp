#include "qt_ship.hpp"

#include "qt_sprite_manager.hpp"

using biv::QtShip;

QtShip::QtShip(const Coord& top_left, const int width, const int height)
	: Ship(top_left, width, height) {}

void QtShip::draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const {
	const QPixmap& top_sprite = QtSpriteManager::get_ship();
	const QPixmap& sub_sprite = QtSpriteManager::get_ship_sub();

	int left = get_left();
	int top = get_top();
	int w = get_width();
	int h = get_height();

	for (int dx = 0; dx < w; ++dx) {
		for (int dy = 0; dy < h; ++dy) {
			int px = (left + dx - camera_x) * cell_width;
			int py = (top + dy) * cell_height;
			QRect cell_rect(px, py, cell_width, cell_height);

			const QPixmap& sprite = (dy == 0) ? top_sprite : sub_sprite;
			if (!sprite.isNull()) {
				painter.drawPixmap(cell_rect, sprite);
			}
		}
	}
}
