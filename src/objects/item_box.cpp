#include "item_box.hpp"

using biv::ItemBox;

ItemBox::ItemBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : Box(top_left, width, height), ui_factory(ui_factory) {}

biv::Rect ItemBox::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed ItemBox::get_speed() const noexcept {
	return {0, 0};
}

void ItemBox::process_horizontal_static_collision(Rect* obj) noexcept {}

void ItemBox::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v < 0) {
		kill();
		release_item();
	}
}

void ItemBox::process_vertical_static_collision(Rect* obj) noexcept {}
