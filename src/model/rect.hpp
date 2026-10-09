#pragma once

#include "coord.hpp"
#include "speed.hpp"

namespace biv {
	class Rect {
		protected:
			Coord top_left;
			int width;
			int height;

		public:
			Rect() = default;
			Rect(const Coord& top_left, const int width, const int height);
			virtual ~Rect() = default;

			int get_bottom() const noexcept;
			int get_height() const noexcept;
			int get_left() const noexcept;
			int get_right() const noexcept;
			int get_top() const noexcept;
			float get_x() const noexcept;
			float get_y() const noexcept;

			// Скорость, с которой эта поверхность увлекает за собой тех,
			// кто стоит на ней сверху. Для обычных неподвижных объектов
			// (корабль, ящик) она нулевая; объекты, которые сами двигаются
			// (например, движущаяся платформа), переопределяют метод.
			// Тот, кто стоит на поверхности, просто спрашивает её скорость
			// через Rect* и не должен знать, что это за объект на самом деле.
			virtual Speed get_surface_speed() const noexcept;
	};
}
