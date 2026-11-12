#include "qt_full_box.hpp"

#include "qt_sprite_manager.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : FullBox(top_left, width, height, ui_factory) {}

void QtFullBox::draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const {
	int px = (get_left() - camera_x) * cell_width;
	int py = get_top() * cell_height;
	int pw = get_width() * cell_width;
	int ph = get_height() * cell_height;

	const QPixmap& sprite = is_active_
		? QtSpriteManager::get_full_box()
		: QtSpriteManager::get_full_box_empty();

	if (!sprite.isNull()) {
		painter.drawPixmap(QRect(px, py, pw, ph), sprite);
	}
}
