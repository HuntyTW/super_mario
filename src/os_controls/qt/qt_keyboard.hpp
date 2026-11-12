#pragma once

#include "keyboard.hpp"

namespace biv {
	class QtKeyBoard : public KeyBoard {
		private:
			static bool enabled;
			static bool left_pressed;
			static bool right_pressed;
			static bool jump_pressed;
			static bool exit_pressed;

		public:
			QtKeyBoard();

			UserInput get_user_input() override;
			void on() override;
			void off() override;

			static void handle_key_press(int key);
			static void handle_key_release(int key);
			static void request_exit();
	};
}
