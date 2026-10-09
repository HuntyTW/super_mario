#include "enemy_base.hpp"

using biv::EnemyBase;

EnemyBase::EnemyBase(
    const Coord& top_left,
    const int width,
    const int height
)
: RectMapMovableAdapter(top_left, width, height) {
    vspeed = 0;
    hspeed = 0.2f;
}

biv::Rect EnemyBase::get_rect() const noexcept {
    return {top_left, width, height};
}

biv::Speed EnemyBase::get_speed() const noexcept {
    return {vspeed, hspeed};
}

void EnemyBase::process_horizontal_static_collision(Rect* obj) noexcept {
    hspeed = -hspeed;
    move_horizontally();
}

void EnemyBase::process_mario_collision(Collisionable* mario) noexcept {
    if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
        kill();
    } else {
        mario->kill();
    }
}
