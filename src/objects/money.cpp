#include "money.hpp"

using biv::Money;

Money::Money(const Coord& top_left, const int width, const int height)
	: Collectible(top_left, width, height) {}

void Money::process_mario_collision(Collisionable* mario) noexcept {
	kill();
}
