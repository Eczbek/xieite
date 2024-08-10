#ifndef XIEITE_HEADER_STREAMS_COLOR
#	define XIEITE_HEADER_STREAMS_COLOR

#	include <array>
#	include <cstddef>
#	include <cstdint>
#	include <utility>
#	include "../bits/join.hpp"
#	include "../bits/size.hpp"
#	include "../bits/unjoin.hpp"
#	include "../types/least_integer.hpp"

namespace xieite::streams {
	template<std::size_t channels_ = 3>
	struct Color {
		std::array<std::uint8_t, channels_> data;

		template<std::same_as<std::uint8_t>... Arguments_>
		requires(sizeof...(Arguments_) == channels_)
		constexpr Color(const Arguments_... arguments) noexcept
		: data { arguments... } {}

		constexpr Color(const xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels_> value = 0) noexcept {
			const auto values = xieite::bits::unjoin<std::uint8_t, channels_>(xieite::bits::join(value));
			this->data = ([&values]<std::size_t... i_>(std::index_sequence<i_...>) {
				return std::array<std::uint8_t, channels_> {
					values[channels_ - i_ - 1]...
				};
			})(std::make_index_sequence<channels_>());
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::streams::Color<channels_>&, const xieite::streams::Color<channels_>&) noexcept = default;

		template<typename Self_>
		[[nodiscard]] constexpr decltype(auto) operator[](this Self_&& self, const std::size_t index) noexcept {
			return std::forward_like<Self_>(self.data[index]);
		}

		[[nodiscard]] constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels_> value() const noexcept {
			return ([this]<std::size_t... i_>(std::index_sequence<i_...>) {
				return static_cast<xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels_>>(xieite::bits::join(this->data[i_]...).to_ullong());
			})(std::make_index_sequence<channels_>());
		}
	};
}

#endif
