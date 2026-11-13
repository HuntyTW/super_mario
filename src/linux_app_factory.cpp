#include "linux_app_factory.hpp"

#include "console_ui_factory.hpp"
#include "linux_control_settings.hpp"
#include "linux_keyboard.hpp"

namespace biv {

KeyBoard* LinuxAppFactory::create_keyboard() {
	return new LinuxKeyboard();
}

OSControlSettings* LinuxAppFactory::create_control_settings(int map_height, int map_width) {
	return new LinuxControlSettings(map_height, map_width);
}

UIFactory* LinuxAppFactory::create_ui_factory(Game* game) {
	return new ConsoleUIFactory(game);
}

std::chrono::milliseconds LinuxAppFactory::get_frame_delay() const {
	return std::chrono::milliseconds(50);
}

} // namespace biv
