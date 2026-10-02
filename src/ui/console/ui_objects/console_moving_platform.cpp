#include "console_moving_platform.hpp"

using biv::ConsoleMovingPlatform;

ConsoleMovingPlatform::ConsoleMovingPlatform(
	const Coord& top_left, const int width, const int height,
	const float range
) : MovingPlatform(top_left, width, height, range) {}

char ConsoleMovingPlatform::get_brush() const noexcept {
	return '=';
}
