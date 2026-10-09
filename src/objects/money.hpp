#pragma once

#include "collectible.hpp"

namespace biv {
	class Money : public Collectible {
		public:
			Money(const Coord& top_left, const int width, const int height);

			void process_mario_collision(Collisionable*) noexcept override;
	};
}
