#include "jumping_enemy.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, const int width, const int height)
	: Enemy(top_left, width, height) {
	hspeed = 0;
}

// ----------------------------------------------------------------------------
// 									VIRTUAL
// ----------------------------------------------------------------------------
void JumpingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	// Враг не двигается по горизонтали, поэтому боковые
	// столкновения игнорируются.
}

void JumpingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Приземлились - гасим вертикальную скорость и тут же
	// прыгаем заново, чтобы получить постоянные прыжки на месте.
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
	jump();
}
