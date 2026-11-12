#include "qt_game_map.hpp"

#include <algorithm>

using biv::QtGameMap;
using biv::QtGameWindow;
using biv::QtUIObject;

QtGameMap::QtGameMap(const int height, const int width)
	: GameMap(height, width), window(new QtGameWindow(height, width)) {
	window->show();
}

QtGameMap::~QtGameMap() {
	delete window;
}

void QtGameMap::add_obj(QtUIObject* obj) {
	objs.push_back(obj);
}

void QtGameMap::clear() noexcept {}

void QtGameMap::refresh() noexcept {
	if (window != nullptr) {
		window->set_objects(objs);
	}
}

void QtGameMap::remove_obj(QtUIObject* obj) {
	objs.erase(std::remove(objs.begin(), objs.end(), obj), objs.end());
	if (window != nullptr) {
		window->set_objects(objs);
	}
}

void QtGameMap::remove_objs() {
	objs.clear();
	if (window != nullptr) {
		window->set_objects(objs);
	}
}

void QtGameMap::show() const noexcept {
	if (window != nullptr) {
		window->render_frame();
	}
}

QtGameWindow* QtGameMap::get_window() const noexcept {
	return window;
}
