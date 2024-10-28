export module xieite:color;

import std;
import :bit_join;
import :bit_size;
import :bit_unjoin;
import :make_array;
import :unroll;
import :least_uint;

export namespace xieite {
	template<std::size_t channels>
	struct color {
		std::array<std::uint8_t, channels> data;

		template<std::convertible_to<std::uint8_t>... Args>
		requires(sizeof...(Args) == channels)
		explicit constexpr color(Args... args) noexcept
		: data { static_cast<std::uint8_t>(args)... } {}

		explicit constexpr color(xieite::least_uint<xieite::bit_size<std::uint8_t> * channels> value = 0) noexcept
		: data(xieite::make_array<std::uint8_t, channels>(std::views::reverse(xieite::bit_unjoin<std::uint8_t, channels>(xieite::bit_join(value))))) {}

		[[nodiscard]] friend bool operator==(const xieiete::color<channels>&, const xieite::color<channels>&) = default;

		template<typename Self>
		[[nodiscard]] constexpr auto&& operator[](this Self&& self, std::size_t idx) noexcept {
			return std::forward_like<Self>(self.data[idx]);
		}

		[[nodiscard]] constexpr xieite::least_uint<xieite::bit_size<std::uint8_t> * channels> value() const noexcept {
			return xieite::unroll<channels>([this]<std::size_t... i> {
				return static_cast<xieite::least_uint<xieite::bit_size<std::uint8_t> * channels>>(xieite::bit_join(this->data[i]...).to_ullong());
			});
		}
	};
}
