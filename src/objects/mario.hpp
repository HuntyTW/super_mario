#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "speed.hpp"

namespace biv {
	class MovingPlatform;

	class Mario : public Movable, public Collisionable {
		private:
			// Платформа, на которой Марио стоит сейчас (nullptr, если он
			// не на движущейся платформе). Перенос применяется каждый кадр
			// в move_horizontally(), а не только в момент приземления -
			// иначе из-за округления в Rect::get_top()/get_bottom()
			// столкновение обнаруживается не каждый тик, и Марио отстаёт
			// от платформы и соскальзывает с неё.
			MovingPlatform* current_platform = nullptr;

		public:
			Mario(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;
			
			void move_horizontally() noexcept override;
			void move_map_left() noexcept;
			void move_map_right() noexcept;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
