#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "heart.hpp"

namespace biv {
	class ConsoleHeart : public Heart, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleHeart(const Coord& top_left, const int width, const int height);

			char get_brush() const noexcept override;
	};
}
