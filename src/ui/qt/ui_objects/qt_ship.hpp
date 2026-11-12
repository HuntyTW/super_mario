#pragma once

#include "qt_ui_obj_rect_adapter.hpp"
#include "ship.hpp"

namespace biv {
	class QtShip : public Ship, public QtUIObjectRectAdapter {
		public:
			QtShip(const Coord& top_left, const int width, const int height);

			void draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const override;
	};
}
