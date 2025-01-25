#pragma once

#include <cstdint>

namespace xieite {
	struct color3 {
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;

		[[nodiscard]] explicit constexpr color3(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept
		: r(r), g(g), b(b) {}

		[[nodiscard]] explicit constexpr color3(std::uint_least32_t n = 0) noexcept
		: r((n >> 16) & 0xFF), g((n >> 8) & 0xFF), b(n & 0xFF) {}

		[[nodiscard]] friend bool operator==(const xieite::color3&, const xieite::color3&) = default;

		[[nodiscard]] constexpr std::uint_least32_t value() const noexcept {
			return (static_cast<std::uint_least32_t>(this->r) << 16) | (static_cast<std::uint_least32_t>(this->g) << 8) | this->b;
		}
	};
}
