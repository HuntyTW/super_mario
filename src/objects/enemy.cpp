#include "enemy.hpp"

using biv::Enemy;

Enemy::Enemy(const Coord& top_left, const int width, const int height)
	: AbstractEnemy(top_left, width, height) {}

void Enemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Проверка: не свалился ли враг с корабля.
	// Т.е., если он на краю, то он должен развернуться
	// и побежать в обратную сторону.
	top_left.x += hspeed;
	if (!has_collision(obj)) {
		process_horizontal_static_collision(obj);
	} else {
		top_left.x -= hspeed;
	}

	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
}
