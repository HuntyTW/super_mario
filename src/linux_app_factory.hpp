#pragma once

#include "app_factory.hpp"

namespace biv {

	/**
	 * Фабрика для работы в терминале Linux (ncurses).
	 */
	class LinuxAppFactory : public AppFactory {
		public:
			KeyBoard* create_keyboard() override;
			OSControlSettings* create_control_settings(int map_height, int map_width) override;
			UIFactory* create_ui_factory(Game* game) override;
			std::chrono::milliseconds get_frame_delay() const override;
	};

	using LinuxConsoleAppFactory = LinuxAppFactory;

} // namespace biv
