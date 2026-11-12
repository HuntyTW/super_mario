#pragma once

#include "moving_platform.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtMovingPlatform : public MovingPlatform, public QtUIObjectRectAdapter {
		public:
			QtMovingPlatform(
				const Coord& top_left,
				const int width, const int height,
				const float range
			);

			void draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const override;
	};
}
