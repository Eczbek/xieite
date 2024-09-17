export module xieite:streams.Color;

import std;
import :bits.join;
import :bits.size;
import :bits.unjoin;
import :types.LeastInteger;

export namespace xieite::streams {
	template<std::size_t channels>
	struct Color {
		std::array<std::uint8_t, channels> data;

		template<std::convertible_to<std::uint8_t>... Arguments>
		requires(sizeof...(Arguments) == channels)
		explicit constexpr Color(const Arguments... arguments) noexcept
		: data { static_cast<std::uint8_t>(arguments)... } {}

		explicit constexpr Color(const xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value = 0) noexcept
		: data(([value]<std::size_t... i>(std::index_sequence<i...>) {
			const auto values = xieite::bits::unjoin<std::uint8_t, channels>(xieite::bits::join(value));
			return std::array<std::uint8_t, channels> {
				values[channels - i - 1]...
			};
		})(std::make_index_sequence<channels>())) {}

		friend bool operator==(const xieite::streams::Color<channels>&, const xieite::streams::Color<channels>&) = default;

		template<typename Self>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, const std::size_t index) noexcept {
			return std::forward_like<Self>(self.data[index]);
		}

		[[nodiscard]] constexpr xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels> value() const noexcept {
			using Result = xieite::types::LeastInteger<xieite::bits::size<std::uint8_t> * channels>;
			return ([this]<std::size_t... i>(std::index_sequence<i...>) {
				return static_cast<Result>(xieite::bits::join(this->data[i]...).to_ullong());
			})(std::make_index_sequence<channels>());
		}
	};
}
