#include "console_mario.hpp"

using biv::ConsoleMario;

ConsoleMario::ConsoleMario(const Coord& top_left, const int width, const int height) 
	: Mario(top_left, width, height) {}

char ConsoleMario::get_brush() const noexcept {
	// Бессмертный Марио рисуется другим символом.
	if (is_immortal()) {
		return 'M';
	}
	return '@';
}
