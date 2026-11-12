#pragma once

#include "heart_box.hpp"
#include "qt_ui_obj_rect_adapter.hpp"

namespace biv {
	class QtHeartBox : public HeartBox, public QtUIObjectRectAdapter {
		public:
			QtHeartBox(
				const Coord& top_left,
				const int width, const int height,
				UIFactory* ui_factory
			);

			void draw(QPainter& painter, int cell_width, int cell_height, int camera_x) const override;
	};
}
