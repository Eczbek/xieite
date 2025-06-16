#ifndef DETAIL_XIEITE_HEADER_MATH_COLOR4
#	define DETAIL_XIEITE_HEADER_MATH_COLOR4
#
#	include <cstdint>

namespace xieite {
	struct color4 {
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;
		std::uint8_t a;

		[[nodiscard]] constexpr color4(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 0xFF) noexcept
		: r(r), g(g), b(b), a(a) {}

		[[nodiscard]] explicit(false) constexpr color4(std::uint_least32_t x = 0xFF) noexcept
		: r(static_cast<std::uint8_t>(x >> 24))
		, g(static_cast<std::uint8_t>(x >> 16))
		, b(static_cast<std::uint8_t>(x >> 8))
		, a(static_cast<std::uint8_t>(x))
		{}

		[[nodiscard]] friend bool operator==(const xieite::color4&, const xieite::color4&) = default;

		[[nodiscard]] constexpr std::uint_least32_t value() const noexcept {
			return (static_cast<std::uint_least32_t>(this->r) << 24)
				| (static_cast<std::uint_least32_t>(this->g) << 16)
				| (static_cast<std::uint_least32_t>(this->b) << 8)
				| static_cast<std::uint_least32_t>(this->a);
		}
	};
}

#endif
