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

		[[nodiscard]] constexpr color4(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) noexcept
		: r(r), g(g), b(b), a(a) {}

		[[nodiscard]] explicit(false) constexpr color4(std::uint_least32_t x = 0) noexcept
		: r((x >> 24) & 0xFF), g((x >> 16) & 0xFF), b((x >> 8) & 0xFF), a(x & 0xFF) {}

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
