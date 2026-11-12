#pragma once

#include <QWidget>
#include <vector>

#include "qt_ui_obj.hpp"

namespace biv {
	class QtGameWindow : public QWidget {
		Q_OBJECT

		private:
			const int map_height;
			const int map_width;
			std::vector<QtUIObject*> objs;

		public:
			QtGameWindow(const int height, const int width, QWidget* parent = nullptr);

			void set_objects(const std::vector<QtUIObject*>& objects);
			void render_frame();

		protected:
			void paintEvent(QPaintEvent* event) override;
			void keyPressEvent(QKeyEvent* event) override;
			void keyReleaseEvent(QKeyEvent* event) override;
			void closeEvent(QCloseEvent* event) override;
	};
}
