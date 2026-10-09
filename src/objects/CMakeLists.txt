target_sources(${PROJECT_NAME}
	PRIVATE
		collectible.cpp
		full_box.cpp
		heart.cpp
		heart_box.cpp
		item_box.cpp
		enemy.cpp
		enemy_base.cpp
		flying_enemy.cpp
		jumping_enemy.cpp
		mario.cpp
		money.cpp
		moving_platform.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
