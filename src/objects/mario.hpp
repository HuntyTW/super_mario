#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "speed.hpp"

namespace biv {
	class Mario : public Movable, public Collisionable {
		private:
			// Поверхность, на которой Марио стоит сейчас (nullptr, если он
			// ни на чём не стоит). Какой именно это объект - корабль, ящик
			// или движущаяся платформа - Марио не знает и не должен знать:
			// он лишь спрашивает у неё скорость (Rect::get_surface_speed()).
			// Перенос применяется каждый кадр в move_horizontally(), а не
			// только в момент приземления - иначе из-за округления в
			// Rect::get_top()/get_bottom() столкновение обнаруживается не
			// каждый тик, и Марио отстаёт от поверхности и соскальзывает.
			const Rect* support = nullptr;

			// Бессмертие: после подбора сердечка. Бессмертный Марио не
			// погибает от врагов, но от падения за карту всё равно
			// погибает (это проверяется отдельно в главном цикле).
			bool immortal = false;

		public:
			Mario(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;
			
			bool is_immortal() const noexcept override;
			void make_immortal() noexcept override;

			void move_horizontally() noexcept override;
			void move_map_left() noexcept;
			void move_map_right() noexcept;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
