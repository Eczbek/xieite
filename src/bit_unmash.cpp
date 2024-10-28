export module xieite:bit_unmash;

import std;
import :bit_size;
import :unroll;
import :least_uint;
import :try_unsigned;

export namespace xieite {
	template<std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::tuple<xieite::least_uint<sizes>...> bit_unmash(std::bitset<bits> value) noexcept {
		std::tuple<xieite::least_uint<sizes>...> result;
		xieite::unroll<sizeof...(sizes)>([&value, &result]<std::size_t... i> {
			(..., (std::get<i>(result) = static_cast<xieite::least_uint<sizes>>(std::exchange(value, value >> sizes).to_ullong()) & (std::numeric_limits<xieite::least_uint<sizes>>::max() >> (xieite::bit_size<xieite::least_uint<sizes>> - sizes))));
		});
		return result;
	}

	template<std::integral T, std::size_t... sizes, std::size_t bits>
	requires(bits >= (... + sizes))
	[[nodiscard]] constexpr std::array<T, sizeof...(sizes)> bit_unmash(std::bitset<bits> value) noexcept {
		return std::array<T, sizeof...(sizes)> {
			([&value] {
				const T item = static_cast<T>(value.to_ullong()) & (std::numeric_limits<xieite::try_unsigned<T>>::max() >> (xieite::bit_size<T> - sizes));
				value >>= sizes;
				return item;
			})()...
		};
	}
}
