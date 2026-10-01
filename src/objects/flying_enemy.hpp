/**
	FlyingEnemy - летающий враг.

	В отличие от обычного Enemy, он не подчиняется гравитации
	(Movable::move_vertically), а летает вверх-вниз в пределах
	амплитуды вокруг точки появления, при этом продолжая
	двигаться по горизонтали и отражаясь от препятствий
	(логика унаследована от Enemy).
*/

#pragma once

#include "enemy.hpp"

namespace biv {
	class FlyingEnemy : public Enemy {
		private:
			static constexpr float AMPLITUDE = 4.0f;
			static constexpr float FLY_SPEED = 0.15f;

			float base_y;

		public:
			FlyingEnemy(const Coord& top_left, const int width, const int height);

			void move_vertically() noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
