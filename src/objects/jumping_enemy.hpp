/**
	JumpingEnemy - враг, прыгающий на месте.

	Не двигается по горизонтали (hspeed = 0) и, приземлившись
	на статический объект, сразу же прыгает заново, используя
	унаследованный от Movable::jump().
*/

#pragma once

#include "enemy.hpp"

namespace biv {
	class JumpingEnemy : public Enemy {
		public:
			JumpingEnemy(const Coord& top_left, const int width, const int height);

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
