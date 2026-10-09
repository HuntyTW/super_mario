#include "mario.hpp"

#include "map_movable.hpp"

using biv::Mario;

Mario::Mario(const Coord& top_left, const int width, const int height) 
	: Movable(top_left, width, height, 0, 0) {}

biv::Rect Mario::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed Mario::get_speed() const noexcept {
	return {vspeed, hspeed};
}

bool Mario::is_immortal() const noexcept {
	return immortal;
}

void Mario::make_immortal() noexcept {
	immortal = true;
}

void Mario::move_horizontally() noexcept {
	Movable::move_horizontally();
	if (support != nullptr) {
		// Перенос каждый кадр, а не только в момент обнаружения
		// столкновения - иначе из-за округления Марио периодически
		// отстаёт от поверхности и слетает с неё. У неподвижных
		// поверхностей скорость нулевая, так что они ничего не меняют.
		top_left.x += support->get_surface_speed().h;
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
		// Марио упал на какую-то поверхность - стоим на ней сверху,
		// запоминаем её для переноса в move_horizontally().
		top_left.y -= vspeed;
		support = obj;
	} else if (vspeed < 0) {
		// Марио ударился головой о полку снизу и после этого должен
		// падать вниз - он ни на чём не "стоит".
		top_left.y -= vspeed;
		support = nullptr;
	}
	vspeed = 0;
}
