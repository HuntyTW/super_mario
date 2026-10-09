#include "console_heart.hpp"

using biv::ConsoleHeart;

ConsoleHeart::ConsoleHeart(const Coord& top_left, const int width, const int height)
	: Heart(top_left, width, height) {}

char ConsoleHeart::get_brush() const noexcept {
	return '&';
}
