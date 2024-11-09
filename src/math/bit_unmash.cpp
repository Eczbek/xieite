export module xieite:bit_unmash;

import std;
import :bit_size;
import :least_uint;
import :repeat;
import :try_unsign;

export namespace xieite {
	template<std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::tuple<xieite::least_uint<sizes>...> bit_unmash(std::bitset<bits> value) noexcept {
		std::tuple<xieite::least_uint<sizes>...> result;
		xieite::repeat<sizeof...(sizes)>([&value, &result]<std::size_t i> -> void {
			static constexpr std::size_t size = (std::array<std::size_t, sizeof...(sizes)> { sizes... })[i];
			using T = xieite::least_uint<size>;
			std::get<i>(result) = static_cast<T>(std::exchange(value, value >> size).to_ullong()) & (std::numeric_limits<T>::max() >> (xieite::bit_size<T> - size));
		});
		return result;
	}

	template<std::integral T, std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::array<T, sizeof...(sizes)> bit_unmash(std::bitset<bits> value) noexcept {
		return std::array<T, sizeof...(sizes)> {
			([&value] -> T {
				const T item = static_cast<T>(value.to_ullong()) & (std::numeric_limits<xieite::try_unsign<T>>::max() >> (xieite::bit_size<T> - sizes));
				value >>= sizes;
				return item;
			})()...
		};
	}
}
