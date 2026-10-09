#include "enemy_base.hpp"

using biv::AbstractEnemy;

AbstractEnemy::AbstractEnemy(const Coord& top_left, const int width, const int height)
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect AbstractEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed AbstractEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void AbstractEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void AbstractEnemy::process_mario_collision(Collisionable* mario) noexcept {
	bool stomped = (
		mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION
	);
	if (stomped || mario->is_immortal()) {
		kill();
	} else {
		mario->kill();
	}
}
