#pragma once

#include <vector>

#include "game_map.hpp"
#include "qt_game_window.hpp"
#include "qt_ui_obj.hpp"

namespace biv {
	class QtGameMap : public GameMap {
		private:
			QtGameWindow* window;
			std::vector<QtUIObject*> objs;

		public:
			QtGameMap(const int height, const int width);
			~QtGameMap();

			void add_obj(QtUIObject* obj);
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_obj(QtUIObject* obj);
			void remove_objs() override;
			void show() const noexcept override;

			QtGameWindow* get_window() const noexcept;
	};
}
