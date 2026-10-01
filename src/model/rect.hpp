#pragma once

#include "coord.hpp"

namespace biv {
	class Rect {
		protected:
			Coord top_left;
			int width;
			int height;

		public:
			Rect() = default;
			Rect(const Coord& top_left, const int width, const int height);
			// Виртуальный деструктор делает Rect полиморфным типом:
			// это нужно, например, для dynamic_cast<MovingPlatform*>
			// в Mario::process_vertical_static_collision.
			virtual ~Rect() = default;

			int get_bottom() const noexcept;
			int get_height() const noexcept;
			int get_left() const noexcept;
			int get_right() const noexcept;
			int get_top() const noexcept;
			float get_x() const noexcept;
			float get_y() const noexcept;
	};
}
