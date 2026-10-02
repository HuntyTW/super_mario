/**
	ImpossibleLevel - уровень для задания:
	"Создать уровень, который не сможет пройти преподаватель".

	Состоит из очень узких кораблей, разделённых большими
	промежутками, которые можно преодолеть только прыжком
	с движущейся платформы в очень узкое окно времени,
	а также из плотных скоплений врагов на местах приземления.
*/

#pragma once

#include "game_level.hpp"

namespace biv {
	class ImpossibleLevel : public GameLevel {
		public:
			ImpossibleLevel(UIFactory* ui_factory);

			GameLevel* get_next() override;
			bool is_final() const noexcept override;

		private:
			void init_data() override;
	};
}
