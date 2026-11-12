#pragma once

#include <QPixmap>
#include <QString>

namespace biv {
	class QtSpriteManager {
		public:
			static const QPixmap& get_mario();
			static const QPixmap& get_mario_immortal();
			static const QPixmap& get_box();
			static const QPixmap& get_full_box();
			static const QPixmap& get_full_box_empty();
			static const QPixmap& get_heart_box();
			static const QPixmap& get_enemy();
			static const QPixmap& get_jumping_enemy();
			static const QPixmap& get_flying_enemy();
			static const QPixmap& get_money();
			static const QPixmap& get_heart();
			static const QPixmap& get_ship();
			static const QPixmap& get_ship_sub();
			static const QPixmap& get_moving_platform();

		private:
			static QPixmap load_pixmap(const QString& name);
	};
}
