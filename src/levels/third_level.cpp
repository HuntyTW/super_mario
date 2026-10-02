#include "third_level.hpp"

#include "impossible_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* ThirdLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ImpossibleLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);

	ui_factory->create_ship({20, 25}, 40, 2);
	ui_factory->create_enemy({25, 20}, 3, 2);
	ui_factory->create_jumping_enemy({35, 20}, 3, 2);

	ui_factory->create_full_box({45, 15}, 5, 3);
	ui_factory->create_full_box({55, 15}, 5, 3);
	ui_factory->create_box({65, 15}, 5, 3);
	ui_factory->create_flying_enemy({50, 10}, 3, 2);

	// Ряд платформ-«ступенек» над водой, соединённых движущейся платформой.
	ui_factory->create_ship({75, 22}, 10, 2);
	ui_factory->create_moving_platform({95, 20}, 6, 2, 12);
	ui_factory->create_ship({115, 22}, 10, 2);
	ui_factory->create_jumping_enemy({117, 17}, 3, 2);

	ui_factory->create_ship({130, 18}, 15, 7);
	ui_factory->create_enemy({132, 13}, 3, 2);
	ui_factory->create_enemy({140, 13}, 3, 2);
	ui_factory->create_flying_enemy({135, 8}, 3, 2);

	ui_factory->create_full_box({155, 15}, 5, 3);
	ui_factory->create_moving_platform({170, 20}, 6, 2, 8);

	ui_factory->create_ship({185, 25}, 40, 2);
	ui_factory->create_enemy({195, 20}, 3, 2);
	ui_factory->create_jumping_enemy({205, 20}, 3, 2);
	ui_factory->create_flying_enemy({215, 15}, 3, 2);
}
