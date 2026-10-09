#include "full_box.hpp"

using biv::FullBox;

FullBox::FullBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : ItemBox(top_left, width, height, ui_factory) {}

void FullBox::release_item() noexcept {
	ui_factory->create_money({top_left.x, top_left.y - 3}, 3, 2);
}
