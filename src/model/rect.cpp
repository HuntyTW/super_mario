#include "rect.hpp"

#include <cmath>

using biv::Rect;

Rect::Rect(const Coord& top_left, const int width, const int height)
	: top_left(top_left), width(width), height(height) {}

int Rect::get_bottom() const noexcept {
	return std::round(top_left.y + height);
}

int Rect::get_height() const noexcept {
	return height;
}

int Rect::get_left() const noexcept {
	return std::round(top_left.x);
}

int Rect::get_right() const noexcept {
	return std::round(top_left.x + width);
}

int Rect::get_top() const noexcept {
	return std::round(top_left.y);
}

float Rect::get_x() const noexcept {
	return top_left.x;
}

float Rect::get_y() const noexcept {
	return top_left.y;
}

biv::Speed Rect::get_surface_speed() const noexcept {
	return {0.0f, 0.0f};
}
