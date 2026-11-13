#include "windows_app_factory.hpp"

#include "console_ui_factory.hpp"
#include "windows_control_settings.hpp"
#include "windows_keyboard.hpp"

namespace biv {

KeyBoard* WindowsAppFactory::create_keyboard() {
	return new WindowsKeyBoard();
}

OSControlSettings* WindowsAppFactory::create_control_settings(int map_height, int map_width) {
	return new WindowsControlSettings(map_height, map_width);
}

UIFactory* WindowsAppFactory::create_ui_factory(Game* game) {
	return new ConsoleUIFactory(game);
}

std::chrono::milliseconds WindowsAppFactory::get_frame_delay() const {
	return std::chrono::milliseconds(10);
}

} // namespace biv
