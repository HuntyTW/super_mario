/**
	JumpingEnemy - враг, прыгающий на месте.

	Наследуется от абстрактного AbstractEnemy напрямую (а не от
	конкретного "ходящего" Enemy) - это отдельный, равноправный вид
	врага. Не двигается по горизонтали (hspeed = 0) и, приземлившись
	на статический объект, сразу же прыгает заново, используя
	унаследованный от Movable::jump().
*/

#pragma once

#include "enemy_base.hpp"

namespace biv {
	class JumpingEnemy : public AbstractEnemy {
		public:
			JumpingEnemy(const Coord& top_left, const int width, const int height);

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
