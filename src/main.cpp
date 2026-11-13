/**
	Игровой цикл - это обощённое представление потока событий, происходящих в игре.

	Игровой цикл:
		1. Установка параметров игры
		2. Получение пользовательского ввода
		3. Обновление внутреннего состояния игры
		4. Обновление изображения на экране
		5. Проверка того, не окончена ли игра

		*** Если игра не окончена, то возвращаемся в пункт № 2.

		6. Завершение
		
	- Какие архитектурные принципы применены при реализации игры?
	
	- На основе какого приципа ООП построен алгоритм игры?
	- Какими элементами языка С++ реализуется этот принцип?
	- Приведите примеры кода, отображающие этот прицип.
*/
#include <thread>

#include "app_factory.hpp"
#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"
#include "keyboard.hpp"
#include "mario.hpp"
#include "os_control_settings.hpp"
#include "second_level.hpp"
#include "ui_factory.hpp"

int main(int argc, char* argv[]) {
	// 1. Установка параметров игры
	using namespace std::chrono_literals;
	
	const int map_height = 30;
	const int map_weight = 200;
	
	biv::AppFactory* app_factory = nullptr;
	#ifdef WINDOWS_CONSOLE
		app_factory = new biv::WindowsAppFactory();
	#elif defined(LINUX_CONSOLE)
		app_factory = new biv::LinuxAppFactory();
	#elif defined(QT_GUI)
		app_factory = new biv::QtAppFactory(argc, argv);
	#endif
	
	biv::KeyBoard* keyboard = app_factory->create_keyboard();
	biv::OSControlSettings* control_settings = app_factory->create_control_settings(map_height, map_weight);
	auto frame_delay = app_factory->get_frame_delay();
	
	control_settings->init();
	keyboard->on();
	
	biv::Game game;
	biv::UIFactory* ui_factory = app_factory->create_ui_factory(&game);

	biv::GameMap* game_map = ui_factory->get_game_map(map_height, map_weight);
	// ВРЕМЕННО (для теста платформ): старт сразу со второго уровня.
	// Чтобы вернуть обычный старт с первого уровня - верни
	// `new biv::FirstLevel(ui_factory)` и include "first_level.hpp" выше.
	biv::GameLevel* game_level = new biv::SecondLevel(ui_factory);
	biv::Mario* mario = ui_factory->get_mario();
	
	biv::UserInput user_input;
	do {
		// 2. Получение пользовательского ввода	
		user_input = keyboard->get_user_input();
		switch (user_input) {
			case biv::UserInput::MAP_LEFT:
				mario->move_map_left();
				if (!game.check_static_collisions(mario)) {
					game.move_map_left();
				}
				mario->move_map_right();
				break;
			case biv::UserInput::MAP_RIGHT:
				mario->move_map_right();
				if (!game.check_static_collisions(mario)) {
					game.move_map_right();
				}
				mario->move_map_left();
				break;
			case biv::UserInput::MARIO_JUMP:
				mario->jump();
				break;
			case biv::UserInput::EXIT:
				game.finish();
				break;
		}
		
		// 3. Обновление внутреннего состояния игры
		game.move_objs_horizontally();
		game.check_horizontally_static_collisions();
		
		game.move_objs_vertically();
		game.check_mario_collision();
		game.check_vertically_static_collisions();
		
		// Падение за карту убирает Марио даже когда он бессмертен
		// (бессмертие защищает только от врагов).
		if (
			game_map->is_below_map(mario->get_top())
			|| !mario->is_active()
		) {
			keyboard->off();
			keyboard->on();
			game_level->restart();
			mario = ui_factory->get_mario();
			std::this_thread::sleep_for(1000ms);
		}
		
		if (game.is_level_end()) {
			if (!game_level->is_final()) {
				game_level = game_level->get_next();
				mario = ui_factory->get_mario();
				std::this_thread::sleep_for(1000ms);
				keyboard->off();
				keyboard->on();
				game.start_level();
			} else {
				game.finish();
			}
		}
		
		// 4. Обновление изображения на экране
		game_map->refresh();
		control_settings->set_cursor_start_position();
		game_map->show();
		std::this_thread::sleep_for(frame_delay);
	} while (
		/* 5. Проверка того, не окончена ли игра */ 
		!game.is_finished()
	);
	
	// 6. Завершение
	delete game_level;
	delete ui_factory;
	delete keyboard;
	delete control_settings;
	delete app_factory;

	return 0;
}
