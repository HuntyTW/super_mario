#pragma once

#include "item_box.hpp"

namespace biv {
	// Коробка, из которой выпадает сердечко (делает Марио бессмертным).
	class HeartBox : public ItemBox {
		protected:
			void release_item() noexcept override;

		public:
			HeartBox(
				const Coord& top_left,
				const int width, const int height,
				UIFactory* ui_factory
			);
	};
}
