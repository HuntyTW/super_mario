#include "mario.hpp"

#include "map_movable.hpp"
#include "moving_platform.hpp"

using biv::Mario;

Mario::Mario(const Coord& top_left, const int width, const int height) 
	: Movable(top_left, width, height, 0, 0) {}

biv::Rect Mario::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Mario::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void Mario::move_horizontally() noexcept {
	if (current_platform != nullptr) {
		// Перенос каждый кадр, а не только в момент обнаружения
		// столкновения - иначе из-за округления Марио периодически
		// отстаёт от платформы и слетает с неё.
		top_left.x += current_platform->get_speed().h;
	} else {
		Movable::move_horizontally();
	}
}

void Mario::move_map_left() noexcept {
	move_horizontal_offset(biv::MapMovable::MAP_STEP);
}

void Mario::move_map_right() noexcept {
	move_horizontal_offset(-biv::MapMovable::MAP_STEP);
}

void Mario::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void Mario::process_mario_collision(Collisionable* mario) noexcept {}

void Mario::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		// Марио упал на корабль (или на движущуюся платформу) - стоим
		// на нём сверху, запоминаем платформу для переноса в move_horizontally().
		top_left.y -= vspeed;
		current_platform = dynamic_cast<MovingPlatform*>(obj);
	} else if (vspeed < 0) {
		// Марио ударился головой о полку снизу и после этого должен
		// падать вниз - он не "стоит" ни на какой платформе.
		top_left.y -= vspeed;
		current_platform = nullptr;
	}
	vspeed = 0;
}
