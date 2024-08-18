#ifndef XIEITE_HEADER_STREAMS_COLOR
#	define XIEITE_HEADER_STREAMS_COLOR

#	include <array>
#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include <utility>
#	include "../bits/join.hpp"
#	include "../bits/size.hpp"
#	include "../bits/unjoin.hpp"
#	include "../types/least_integer.hpp"

namespace xieite::streams {
	template<std::size_t channels>
	struct Color {
		std::array<std::uint8_t, channels> data;

		template<std::convertible_to<std::uint8_t>... Arguments>
		requires(sizeof...(Arguments) == channels)
		explicit constexpr Color(const Arguments... arguments) noexcept
		: data { static_cast<std::uint8_t>(arguments)... } {}

		explicit constexpr Color(const xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value = 0) noexcept
		: data(([value]<std::size_t... i>(std::index_sequence<i...>) -> std::array<std::uint8_t, channels> {
			const auto values = xieite::bits::unjoin<std::uint8_t, channels>(xieite::bits::join(value));
			return std::array<std::uint8_t, channels> {
				values[channels - i - 1]...
			};
		})(std::make_index_sequence<channels>())) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::streams::Color<channels>&, const xieite::streams::Color<channels>&) noexcept = default;

		template<typename Self>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, const std::size_t index) noexcept {
			return std::forward_like<Self>(self.data[index]);
		}

		[[nodiscard]] constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value() const noexcept {
			using Result = xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels>;
			return ([this]<std::size_t... i>(std::index_sequence<i...>) -> Result {
				return static_cast<Result>(xieite::bits::join(this->data[i]...).to_ullong());
			})(std::make_index_sequence<channels>());
		}
	};
}

#endif
