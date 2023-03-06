#pragma once
#include <cstdint> // std::uint32_t, std::uint8_t

namespace xieite::graphics {
	struct Color {
		std::uint8_t red;
		std::uint8_t green;
		std::uint8_t blue;
		std::uint8_t alpha;

		constexpr Color(const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue, std::uint8_t alpha = 255) noexcept
		: red(red), green(green), blue(blue), alpha(alpha) {}

		constexpr Color(const std::uint32_t value) noexcept
		: red(value >> 24), green(value >> 16 & 255), blue(value >> 8 & 255), alpha(value & 255) {}

		constexpr bool operator==(const xieite::graphics::Color other) const noexcept {
			return (red == other.red) && (green == other.green) && (blue == other.blue) && (alpha == other.alpha);
		}

		constexpr std::uint32_t value() noexcept {
			return (red << 24) + (green << 16) + (blue << 8) + alpha;
		}
	};
}
