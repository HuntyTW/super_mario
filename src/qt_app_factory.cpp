#include "qt_app_factory.hpp"

#include <QApplication>

#include "qt_control_settings.hpp"
#include "qt_keyboard.hpp"
#include "qt_ui_factory.hpp"

namespace biv {

QtAppFactory::QtAppFactory(int argc, char* argv[])
	: argc(argc), app(std::make_unique<QApplication>(this->argc, argv)) {}

QtAppFactory::~QtAppFactory() = default;

KeyBoard* QtAppFactory::create_keyboard() {
	return new QtKeyBoard();
}

OSControlSettings* QtAppFactory::create_control_settings(int map_height, int map_width) {
	return new QtControlSettings(map_height, map_width);
}

UIFactory* QtAppFactory::create_ui_factory(Game* game) {
	return new QtUIFactory(game);
}

std::chrono::milliseconds QtAppFactory::get_frame_delay() const {
	return std::chrono::milliseconds(16); // ~60 FPS
}

} // namespace biv
