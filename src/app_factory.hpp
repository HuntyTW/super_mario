#pragma once

#include <chrono>
#include <memory>

#include "game.hpp"
#include "keyboard.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"

#ifdef WINDOWS_CONSOLE
	#include "console_ui_factory.hpp"
	#include "windows_control_settings.hpp"
	#include "windows_keyboard.hpp"
#elif defined(LINUX_CONSOLE)
	#include "console_ui_factory.hpp"
	#include "linux_control_settings.hpp"
	#include "linux_keyboard.hpp"
#elif defined(QT_GUI)
	#include <QApplication>
	#include "qt_control_settings.hpp"
	#include "qt_keyboard.hpp"
	#include "qt_ui_factory.hpp"
#endif

namespace biv {

	/**
	 * AppFactory — абстрактная фабрика верхнего уровня приложения.
	 * 
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
	};

#ifdef WINDOWS_CONSOLE
	/**
	 * Фабрика для работы в консоли Windows (cmd/PowerShell).
	 */
	class WindowsAppFactory : public AppFactory {
		public:
			KeyBoard* create_keyboard() override {
				return new WindowsKeyBoard();
			}

			OSControlSettings* create_control_settings(int map_height, int map_width) override {
				return new WindowsControlSettings(map_height, map_width);
			}

			UIFactory* create_ui_factory(Game* game) override {
				return new ConsoleUIFactory(game);
			}

			std::chrono::milliseconds get_frame_delay() const override {
				return std::chrono::milliseconds(10);
			}
	};
	using WindowsConsoleAppFactory = WindowsAppFactory;
#elif defined(LINUX_CONSOLE)
	/**
	 * Фабрика для работы в терминале Linux (ncurses).
	 */
	class LinuxAppFactory : public AppFactory {
		public:
			KeyBoard* create_keyboard() override {
				return new LinuxKeyboard();
			}

			OSControlSettings* create_control_settings(int map_height, int map_width) override {
				return new LinuxControlSettings(map_height, map_width);
			}

			UIFactory* create_ui_factory(Game* game) override {
				return new ConsoleUIFactory(game);
			}

			std::chrono::milliseconds get_frame_delay() const override {
				return std::chrono::milliseconds(50);
			}
	};
	using LinuxConsoleAppFactory = LinuxAppFactory;
#elif defined(QT_GUI)
	/**
	 * Фабрика для работы с графическим интерфейсом Qt.
	 * Инкапсулирует экземпляр QApplication, необходимый для работы оконной системы Qt.
	 */
	class QtAppFactory : public AppFactory {
		private:
			std::unique_ptr<QApplication> app;

		public:
			QtAppFactory(int& argc, char* argv[])
				: app(std::make_unique<QApplication>(argc, argv)) {}

			KeyBoard* create_keyboard() override {
				return new QtKeyBoard();
			}

			OSControlSettings* create_control_settings(int map_height, int map_width) override {
				return new QtControlSettings(map_height, map_width);
			}

			UIFactory* create_ui_factory(Game* game) override {
				return new QtUIFactory(game);
			}

			std::chrono::milliseconds get_frame_delay() const override {
				return std::chrono::milliseconds(16); // ~60 FPS
			}
	};
	using QtFactory = QtAppFactory;
#endif

} // namespace biv
