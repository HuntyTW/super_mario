#pragma once

#include "enemy_base.hpp"

namespace biv {
	class Enemy : public EnemyBase {
	public:
		Enemy(const Coord& top_left, const int width, const int height);

		void process_vertical_static_collision(Rect*) noexcept override;
	};
}
