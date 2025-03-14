#pragma once

#include <array>
#include <bitset>
#include <concepts>
#include "../math/bit_size.hpp"
#include "../trait/try_unsign.hpp"

namespace xieite {
	template<std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + xieite::bit_size<Ts>)> join_bits(Ts... args) noexcept {
		static constexpr std::size_t bits = (... + xieite::bit_size<Ts>);
		std::bitset<bits> result;
		(..., (result = (result >> xieite::bit_size<Ts>) | (std::bitset<bits>(static_cast<xieite::try_unsign<Ts>>(args)) << (bits - xieite::bit_size<Ts>))));
		return result;
	}

	template<std::integral T, std::size_t size>
	[[nodiscard]] constexpr std::bitset<(xieite::bit_size<T> * size)> join_bits(const std::array<T, size>& args) noexcept {
		static constexpr std::size_t bits = xieite::bit_size<T> * size;
		std::bitset<bits> result;
		for (T n : args) {
			result = (result >> xieite::bit_size<T>) | (std::bitset<bits>(static_cast<xieite::try_unsign<T>>(n)) << (bits - xieite::bit_size<T>));
		}
		return result;
	}
}
