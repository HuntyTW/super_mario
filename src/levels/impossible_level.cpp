#include "impossible_level.hpp"

using biv::ImpossibleLevel;

ImpossibleLevel::ImpossibleLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ImpossibleLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ImpossibleLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ImpossibleLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);

	// Стартовая площадка плотно облеплена врагами.
	ui_factory->create_ship({20, 25}, 30, 2);
	ui_factory->create_jumping_enemy({25, 20}, 3, 2);
	ui_factory->create_jumping_enemy({35, 20}, 3, 2);
	ui_factory->create_flying_enemy({45, 12}, 3, 2);

	// Крошечная платформа-мишень: промахнулся - в воду.
	ui_factory->create_ship({70, 25}, 4, 2);
	ui_factory->create_flying_enemy({70, 20}, 3, 2);

	// Быстрая платформа с крошечной амплитудой - поймать
	// момент, когда она окажется точно под Марио, почти нереально.
	ui_factory->create_moving_platform({90, 22}, 4, 2, 2);

	ui_factory->create_ship({105, 25}, 4, 2);
	ui_factory->create_jumping_enemy({105, 20}, 3, 2);

	// Вторая скоростная платформа сразу за первой, без передышки.
	ui_factory->create_moving_platform({120, 20}, 4, 2, 2);

	ui_factory->create_ship({135, 25}, 4, 2);

	// "Частокол" из прыгающих и летающих врагов на подходе к финишу.
	ui_factory->create_ship({150, 25}, 50, 2);
	ui_factory->create_jumping_enemy({155, 20}, 3, 2);
	ui_factory->create_jumping_enemy({165, 20}, 3, 2);
	ui_factory->create_jumping_enemy({175, 20}, 3, 2);
	ui_factory->create_flying_enemy({160, 12}, 3, 2);
	ui_factory->create_flying_enemy({170, 12}, 3, 2);
	ui_factory->create_flying_enemy({180, 12}, 3, 2);
	ui_factory->create_enemy({185, 20}, 3, 2);

	// Финишная площадка - последней статикой должен быть именно
	// этот корабль, чтобы засчитать окончание уровня (и игры).
	ui_factory->create_ship({215, 25}, 30, 2);
}
