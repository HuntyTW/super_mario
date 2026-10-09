/**
	FlyingEnemy - летающий враг.

	Наследуется от абстрактного AbstractEnemy напрямую (а не от
	конкретного "ходящего" Enemy) - это отдельный, равноправный вид
	врага. Реакцию на столкновение со стеной (развернуться и пойти в
	обратную сторону) он переиспользует из AbstractEnemy как есть -
	она не завязана на конкретно "ходящее" поведение. А вот гравитации
	он не подчиняется (Movable::move_vertically переопределён) и летает
	вверх-вниз в пределах амплитуды вокруг точки появления.
*/

#pragma once

#include "enemy_base.hpp"

namespace biv {
	class FlyingEnemy : public AbstractEnemy {
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
