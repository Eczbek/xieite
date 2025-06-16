#ifndef DETAIL_XIEITE_HEADER_MATH_COLOR3
#	define DETAIL_XIEITE_HEADER_MATH_COLOR3
#
#	include <cstdint>

namespace xieite {
	struct color3 {
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;

		[[nodiscard]] constexpr color3(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept
		: r(r), g(g), b(b) {}

		[[nodiscard]] explicit(false) constexpr color3(std::uint_least32_t x = 0) noexcept
		: r(static_cast<std::uint8_t>(x >> 16))
		, g(static_cast<std::uint8_t>(x >> 8))
		, b(static_cast<std::uint8_t>(x))
		{}

		[[nodiscard]] friend bool operator==(const xieite::color3&, const xieite::color3&) = default;

		[[nodiscard]] constexpr std::uint_least32_t value() const noexcept {
			return (static_cast<std::uint_least32_t>(this->r) << 16)
				| (static_cast<std::uint_least32_t>(this->g) << 8) 
				| static_cast<std::uint_least32_t>(this->b);
		}
	};
}

#endif
