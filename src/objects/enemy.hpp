/**
	Enemy - обычный "ходящий" враг: двигается по горизонтали и
	разворачивается у края платформы, по которой идёт.

	Это один из нескольких конкретных видов врагов (наравне с
	FlyingEnemy и JumpingEnemy) - общая часть вынесена в абстрактный
	AbstractEnemy, от которого все они наследуются напрямую, а не
	друг от друга (см. enemy_base.hpp).
*/

#pragma once

#include "enemy_base.hpp"
#include "rect.hpp"

namespace biv {
	class Enemy : public AbstractEnemy {
		public:
			Enemy(const Coord& top_left, const int width, const int height);

			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
