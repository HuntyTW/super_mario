#pragma once

#include "item_box.hpp"

namespace biv {
	// Коробка, из которой выпадает монетка.
	class FullBox : public ItemBox {
		protected:
			void release_item() noexcept override;

		public:
			FullBox(
				const Coord& top_left,
				const int width, const int height,
				UIFactory* ui_factory
			);
	};
}
