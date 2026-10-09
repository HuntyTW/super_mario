#include "heart_box.hpp"

using biv::HeartBox;

HeartBox::HeartBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : ItemBox(top_left, width, height, ui_factory) {}

void HeartBox::release_item() noexcept {
	ui_factory->create_heart({top_left.x, top_left.y - 3}, 3, 2);
}
