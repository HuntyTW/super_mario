#pragma once

#include "os_control_settings.hpp"

namespace biv {
	class WindowsControlSettings : public OSControlSettings {
		private:
			int height;
			int width;

		public:
			WindowsControlSettings(const int height, const int width);

			void init() override;
			void set_cursor_start_position() override;
	};
}
