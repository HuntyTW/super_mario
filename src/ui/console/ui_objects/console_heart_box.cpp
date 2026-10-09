#include "console_heart_box.hpp"

using biv::ConsoleHeartBox;

ConsoleHeartBox::ConsoleHeartBox(
	const Coord& top_left,
	const int width, const int height,
	UIFactory* ui_factory
) : HeartBox(top_left, width, height, ui_factory) {}

char ConsoleHeartBox::get_brush() const noexcept {
	if (is_active_) {
		return '!';
	} else {
		return '-';
	}
}
