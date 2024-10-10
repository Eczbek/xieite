export module xieite:bits.unjoin;

import std;
import :bits.size;
import :functors.unroll;

export namespace xieite::bits {
	template<std::integral... Integrals, std::size_t bits>
	requires(bits >= (... + xieite::bits::size<Integrals>))
	[[nodiscard]] constexpr std::tuple<Integrals...> unjoin(std::bitset<bits> value) noexcept {
		std::tuple<Integrals...> result;
		xieite::functors::unroll<Integrals...>([&value, &result]<std::size_t... i> {
			(..., ([&value, &result] {
				std::get<i>(result) = static_cast<Integrals>(value.to_ullong());
				value >>= xieite::bits::size<Integrals>;
			})());
		});
		return result;
	}

	template<std::integral Integral, std::size_t size, std::size_t bits>
	requires(bits >= (xieite::bits::size<Integral> * size))
	[[nodiscard]] constexpr std::array<Integral, size> unjoin(std::bitset<bits> value) noexcept {
		std::array<Integral, size> result;
		for (std::size_t i = 0; i < size; ++i) {
			result[i] = static_cast<Integral>(value.to_ullong());
			value >>= xieite::bits::size<Integral>;
		}
		return result;
	}
}
