/**
	Collectible - абстрактный базовый класс для предметов, которые
	выпадают из коробок и подбираются Марио (деньги, сердечко и т.д.).

	Общее для всех предметов: геометрия, скорость, реакция на стены и
	корабли (катится, разворачивается у стен, может свалиться с края).
	А вот что именно происходит при подборе - у каждого предмета своё,
	поэтому process_mario_collision() остаётся чисто виртуальным.
*/

#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class Collectible : public RectMapMovableAdapter, public Movable, public Collisionable {
		public:
			Collectible(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_mario_collision(Collisionable*) noexcept override = 0;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}
