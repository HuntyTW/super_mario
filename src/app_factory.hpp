#pragma once

#include <chrono>

#include "game.hpp"
#include "keyboard.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"

namespace biv {

	/**
	 * AppFactory — чистый абстрактный класс фабрики верхнего уровня приложения.
	 * 
	 * Не зависит ни от одной системной библиотеки или DLL (Qt, Windows API, ncurses).
	 * Инкапсулирует создание всех платформозависимых компонентов игры:
	 * - устройства ввода (KeyBoard);
	 * - настроек отображения/консоли/окна (OSControlSettings);
	 * - фабрики графических или консольных игровых объектов (UIFactory);
	 * - задержки кадра (frame_delay) для поддержания целевого FPS.
	 */
	class AppFactory {
		public:
			virtual ~AppFactory() = default;

			/// Создаёт подсистему ввода клавиатуры
			virtual KeyBoard* create_keyboard() = 0;

			/// Создаёт подсистему настроек окна/консоли
			virtual OSControlSettings* create_control_settings(int map_height, int map_width) = 0;

			/// Создаёт абстрактную фабрику игровых объектов (UI)
			virtual UIFactory* create_ui_factory(Game* game) = 0;

			/// Возвращает задержку кадра в миллисекундах для игрового цикла
			virtual std::chrono::milliseconds get_frame_delay() const = 0;

			/// Статический фабричный метод создания конкретной фабрики под текущую платформу
			static AppFactory* create_app_factory(int argc = 0, char* argv[] = nullptr);
	};

} // namespace biv
