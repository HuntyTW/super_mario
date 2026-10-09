/**
	ItemBox - абстрактный базовый класс для коробок, которые нужно
	разбить ударом головы снизу, чтобы из них выпал предмет.

	Общее для всех таких коробок: реакция на удар Марио (коробка
	"ломается" и выпускает предмет). А какой именно предмет выпадает
	(деньги, сердечко и т.д.) - решает наследник в release_item().
*/

#pragma once

#include "box.hpp"
#include "collisionable.hpp"
#include "ui_factory.hpp"

namespace biv {
	class ItemBox : public Box, public Collisionable {
		protected:
			UIFactory* ui_factory;

			// Создаёт предмет, выпадающий из разбитой коробки.
			virtual void release_item() noexcept = 0;

		public:
			ItemBox(
				const Coord& top_left,
				const int width, const int height,
				UIFactory* ui_factory
			);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
