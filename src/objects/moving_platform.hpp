/**
	MovingPlatform - платформа, на которую Марио может запрыгнуть
	и переместиться на ней по карте (например, над морем).

	Это статический для коллизий объект (как Ship/Box), но при
	этом самостоятельно двигается по горизонтали между left_bound
	и right_bound, отражаясь от границ. Для того чтобы Марио
	перемещался вместе с платформой, Mario::process_vertical_static_collision
	дополнительно проверяет, не стоит ли он на MovingPlatform,
	и, если да, переносит его на величину скорости платформы (get_speed().h).
*/

#pragma once

#include "movable.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class MovingPlatform : public RectMapMovableAdapter, public Movable {
		private:
			float left_bound;
			float right_bound;

		public:
			MovingPlatform(
				const Coord& top_left, const int width, const int height,
				const float range
			);

			Speed get_speed() const noexcept;

			void move_horizontally() noexcept override;
			// Платформа висит на фиксированной высоте и не подвержена
			// гравитации (в отличие от Mario/Enemy) - без этого override
			// сработал бы дефолтный Movable::move_vertically(), который
			// каждый кадр разгоняет её вниз, как при падении.
			void move_vertically() noexcept override;
	};
}
