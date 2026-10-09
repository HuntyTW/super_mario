#include "heart.hpp"

using biv::Heart;

Heart::Heart(const Coord& top_left, const int width, const int height)
	: Collectible(top_left, width, height) {}

void Heart::process_mario_collision(Collisionable* mario) noexcept {
	kill();
	mario->make_immortal();
}
