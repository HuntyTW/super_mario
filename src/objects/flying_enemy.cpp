#include "flying_enemy.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height)
	: Enemy(top_left, width, height) {
	base_y = top_left.y;
	vspeed = FLY_SPEED;
	hspeed = 0.15f;
}

// ----------------------------------------------------------------------------
// 									VIRTUAL
// ----------------------------------------------------------------------------
void FlyingEnemy::move_vertically() noexcept {
	// Гравитация игнорируется: враг летает по синусоиде
	// в пределах AMPLITUDE вокруг точки появления.
	top_left.y += vspeed;

	if (top_left.y >= base_y + AMPLITUDE) {
		vspeed = -FLY_SPEED;
	} else if (top_left.y <= base_y - AMPLITUDE) {
		vspeed = FLY_SPEED;
	}
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	// Враг летает над препятствиями и кораблями, поэтому
	// вертикальные столкновения с ними на него не влияют.
}
