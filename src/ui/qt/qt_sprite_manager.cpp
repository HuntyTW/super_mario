#include "qt_sprite_manager.hpp"

#include <QCoreApplication>
#include <QFile>
#include <iostream>

// Принудительная инициализация ресурсов Qt
static void ensure_resources_initialized() {
	static bool initialized = false;
	if (!initialized) {
		initialized = true;
		Q_INIT_RESOURCE(mario);
	}
}

using biv::QtSpriteManager;

QPixmap QtSpriteManager::load_pixmap(const QString& name) {
	ensure_resources_initialized();

	QString qrc_path = QString(":/sprites/%1").arg(name);
	QPixmap pm(qrc_path);
	if (!pm.isNull()) {
		return pm;
	}

	QString app_dir = QCoreApplication::applicationDirPath();
	QStringList fallback_paths = {
		app_dir + "/sprites/" + name,
		app_dir + "/../src/ui/qt/sprites/" + name,
		"sprites/" + name,
		"src/ui/qt/sprites/" + name,
		"../src/ui/qt/sprites/" + name,
		"../../src/ui/qt/sprites/" + name
	};

	for (const QString& path : fallback_paths) {
		if (QFile::exists(path)) {
			QPixmap disk_pm(path);
			if (!disk_pm.isNull()) {
				return disk_pm;
			}
		}
	}

	return QPixmap();
}

const QPixmap& QtSpriteManager::get_mario() {
	static QPixmap pm = load_pixmap("mario.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_mario_immortal() {
	static QPixmap pm = load_pixmap("mario_immortal.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_box() {
	static QPixmap pm = load_pixmap("box.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_full_box() {
	static QPixmap pm = load_pixmap("full_box.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_full_box_empty() {
	static QPixmap pm = load_pixmap("full_box_empty.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_heart_box() {
	static QPixmap pm = load_pixmap("heart_box.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_enemy() {
	static QPixmap pm = load_pixmap("enemy.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_jumping_enemy() {
	static QPixmap pm = load_pixmap("jumping_enemy.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_flying_enemy() {
	static QPixmap pm = load_pixmap("flying_enemy.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_money() {
	static QPixmap pm = load_pixmap("money.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_heart() {
	static QPixmap pm = load_pixmap("heart.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_ship() {
	static QPixmap pm = load_pixmap("ship.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_ship_sub() {
	static QPixmap pm = load_pixmap("ship_sub.png");
	return pm;
}

const QPixmap& QtSpriteManager::get_moving_platform() {
	static QPixmap pm = load_pixmap("moving_platform.png");
	return pm;
}
