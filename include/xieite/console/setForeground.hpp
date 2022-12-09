#pragma once
#include <xieite/graphics/Color.hpp> // xieite::graphics::Color

namespace xieite::console {
	void setForeground() noexcept;

	void setForeground(const xieite::graphics::Color color) noexcept;
}
