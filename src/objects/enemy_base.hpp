/**
	AbstractEnemy - абстрактный базовый класс для всех видов врагов.

	Изначально Enemy был одновременно и "абстракцией врага вообще", и
	конкретной реализацией "ходящего" врага (двигается по горизонтали,
	разворачивается у края платформы). Из-за этого новые виды врагов
	(FlyingEnemy, JumpingEnemy) были вынуждены наследоваться от Enemy -
	то есть от чужой конкретной реализации, а не от общей абстракции,
	и им приходилось "гасить" унаследованное поведение, которое им не
	подходило (например, FlyingEnemy раньше заглушал Enemy::process_vertical_static_collision).

	Теперь AbstractEnemy содержит только то, что действительно общее для
	ВСЕХ врагов (геометрия, скорость, реакция на столкновение с Марио),
	а Enemy, FlyingEnemy и JumpingEnemy - равноправные потомки этой
	абстракции, а не друг друга.
*/

#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class AbstractEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		public:
			AbstractEnemy(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			// Общая для большинства врагов реакция на столкновение со
			// стеной - развернуться и пойти в обратную сторону. Враги,
			// которым это не подходит (например, JumpingEnemy, который
			// не двигается по горизонтали), переопределяют этот метод.
			void process_horizontal_static_collision(Rect*) noexcept override;

			// Общая для всех врагов реакция на столкновение с Марио:
			// либо враг погибает (Марио прыгнул на него сверху или
			// Марио бессмертен), либо погибает Марио.
			void process_mario_collision(Collisionable*) noexcept override;

			// А вот поведение по вертикали у каждого вида врага своё
			// (обычный враг держится на краю платформы, летающий его
			// игнорирует, прыгающий - постоянно подпрыгивает), поэтому
			// метод остаётся чисто виртуальным - именно из-за него
			// AbstractEnemy нельзя инстанцировать напрямую.
			void process_vertical_static_collision(Rect*) noexcept override = 0;
	};
}
