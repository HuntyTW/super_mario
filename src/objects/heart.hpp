/**
	Heart - сердечко: при подборе делает Марио бессмертным.
	Бессмертный Марио не погибает от врагов, а, наоборот, убивает
	их при столкновении (но от падения за карту всё равно погибает).
*/

#pragma once

#include "collectible.hpp"

namespace biv {
	class Heart : public Collectible {
		public:
			Heart(const Coord& top_left, const int width, const int height);

			void process_mario_collision(Collisionable*) noexcept override;
	};
}
