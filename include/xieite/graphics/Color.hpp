#pragma once
#include <cstdint> // std::uint8_t

namespace xieite::graphics {
	struct Color {
		std::uint8_t red;
		std::uint8_t green;
		std::uint8_t blue;

		constexpr Color(const std::uint8_t red = 0, const std::uint8_t green = 0, const std::uint8_t blue = 0) noexcept
		: red(red), green(green), blue(blue) {}
	};
}
