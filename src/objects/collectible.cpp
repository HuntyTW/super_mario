#include "collectible.hpp"

using biv::Collectible;

Collectible::Collectible(const Coord& top_left, const int width, const int height)
	: RectMapMovableAdapter(top_left, width, height) {
	vspeed = 0;
	hspeed = 0.2;
}

biv::Rect Collectible::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Collectible::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Collectible::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Collectible::process_vertical_static_collision(Rect* obj) noexcept {
	// Предметы могут свалиться с корабля: Кто не поймал, тот не успел.

	// Особенность модели вертикального передвижения в игре.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
}
