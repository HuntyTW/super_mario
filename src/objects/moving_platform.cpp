#include "moving_platform.hpp"

using biv::MovingPlatform;

MovingPlatform::MovingPlatform(
	const Coord& top_left, const int width, const int height,
	const float range
) : RectMapMovableAdapter(top_left, width, height) {
	this->vspeed = 0;
	this->hspeed = 0.1f;
	left_bound = top_left.x - range;
	right_bound = top_left.x + range;
}

biv::Speed MovingPlatform::get_speed() const noexcept {
	return {vspeed, hspeed};
}

// ----------------------------------------------------------------------------
// 									VIRTUAL
// ----------------------------------------------------------------------------
void MovingPlatform::move_horizontally() noexcept {
	top_left.x += hspeed;

	if (top_left.x >= right_bound) {
		hspeed = -hspeed;
	} else if (top_left.x <= left_bound) {
		hspeed = -hspeed;
	}
}

void MovingPlatform::move_vertically() noexcept {

}
