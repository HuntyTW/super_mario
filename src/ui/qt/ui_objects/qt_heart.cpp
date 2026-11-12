#include "qt_heart.hpp"

#include "qt_sprite_manager.hpp"

using biv::QtHeart;

QtHeart::QtHeart(const Coord& top_left, const int width, const int height)
	: Heart(top_left, width, height) {}

void QtHeart::draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const {
	int px = (get_left() - camera_x) * cell_width;
	int py = get_top() * cell_height;
	int pw = get_width() * cell_width;
	int ph = get_height() * cell_height;

	const QPixmap& sprite = QtSpriteManager::get_heart();
	if (!sprite.isNull()) {
		painter.drawPixmap(QRect(px, py, pw, ph), sprite);
	}
}
