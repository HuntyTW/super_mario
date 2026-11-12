#pragma once

#include "os_control_settings.hpp"

namespace biv {
	class QtControlSettings : public OSControlSettings {
		private:
			const int height;
			const int width;

		public:
			QtControlSettings(const int height, const int width);

			void init() override;
			void set_cursor_start_position() override;
	};
}
