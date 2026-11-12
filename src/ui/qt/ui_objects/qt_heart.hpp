#pragma once

#include "heart.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtHeart : public Heart, public QtUIObjectRectAdapter {
		public:
			QtHeart(const Coord& top_left, const int width, const int height);

			void draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const override;
	};
}
