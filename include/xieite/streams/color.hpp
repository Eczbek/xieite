#ifndef XIEITE_HEADER_STREAMS_COLOR
#	define XIEITE_HEADER_STREAMS_COLOR

#	include <limits>
#	include <cstdint>
#	include "../bits/join.hpp"
#	include "../bits/unjoin.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::streams {
	struct Color {
		std::uint8_t red;
		std::uint8_t green;
		std::uint8_t blue;

		constexpr Color(const std::uint8_t red = 0, const std::uint8_t green = 0, const std::uint8_t blue = 0) noexcept
		: red(red), green(green), blue(blue) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::streams::Color& color1, const xieite::streams::Color& color2) noexcept {
			return (color1.red == color2.red) && (color1.green == color2.green) && (color1.blue == color2.blue);
		}

		[[nodiscard]] static constexpr xieite::streams::Color from(const std::uint32_t value) noexcept {
			const auto values = xieite::bits::unjoin<std::uint8_t, 4>(xieite::bits::join(value));
			return xieite::streams::Color(values[0], values[1], values[2]);
		}

		[[nodiscard]] constexpr std::uint32_t value() noexcept {
			return static_cast<std::uint32_t>(xieite::bits::join(this->blue, this->green, this->red).to_ullong());
		}
	};
}

#endif
