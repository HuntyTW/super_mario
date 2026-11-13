#pragma once

#include <memory>

#include "app_factory.hpp"

class QApplication;

namespace biv {

	/**
	 * Фабрика для работы с графическим интерфейсом Qt.
	 * Инкапсулирует экземпляр QApplication, необходимый для работы оконной системы Qt.
	 */
	class QtAppFactory : public AppFactory {
		private:
			int argc;
			std::unique_ptr<QApplication> app;

		public:
			QtAppFactory(int argc = 0, char* argv[] = nullptr);
			~QtAppFactory() override;

			KeyBoard* create_keyboard() override;
			OSControlSettings* create_control_settings(int map_height, int map_width) override;
			UIFactory* create_ui_factory(Game* game) override;
			std::chrono::milliseconds get_frame_delay() const override;
	};

	using QtFactory = QtAppFactory;

} // namespace biv
