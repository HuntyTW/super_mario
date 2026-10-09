#pragma once

#include "enemy_base.hpp"

namespace biv {
	class FlyingEnemy : public EnemyBase {
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
