export module xieite:bit_unjoin;

import std;
import :bit_size;
import :repeat;

export namespace xieite {
	template<std::integral... Ts, std::size_t bits>
	requires(bits >= (... + xieite::bit_size<Ts>))
	[[nodiscard]] constexpr std::tuple<Ts...> bit_unjoin(std::bitset<bits> value) noexcept {
		std::tuple<Ts...> result;
		xieite::repeat<Ts...>([&value, &result]<std::size_t i> -> void {
			using T = std::tuple_element_t<i, std::tuple<Ts...>>;
			std::get<i>(result) = static_cast<T>(value.to_ullong());
			value >>= xieite::bit_size<T>;
		});
		return result;
	}

	template<std::integral T, std::size_t size, std::size_t bits>
	requires(bits >= (xieite::bit_size<T> * size))
	[[nodiscard]] constexpr std::array<T, size> bit_unjoin(std::bitset<bits> value) noexcept {
		std::array<T, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<T>(value.to_ullong());
			value >>= xieite::bit_size<T>;
		}
		return result;
	}
}
