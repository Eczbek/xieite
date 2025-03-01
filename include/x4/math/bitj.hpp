#pragma once

#include <array>
#include <bitset>
#include <concepts>
#include "../math/bits.hpp"
#include "../meta/tryunsign.hpp"

namespace x4 {
	template<std::integral... Ts>
	[[nodiscard]] constexpr std::bitset<(... + x4::bits<Ts>)> bitj(Ts... args) noexcept {
		static constexpr std::size_t bits = (... + x4::bits<Ts>);
		std::bitset<bits> result;
		(..., (result = (result >> x4::bits<Ts>) | (std::bitset<bits>(static_cast<x4::tryunsign<Ts>>(args)) << (bits - x4::bits<Ts>))));
		return result;
	}

	template<std::integral T, std::size_t size>
	[[nodiscard]] constexpr std::bitset<(x4::bits<T> * size)> bitj(const std::array<T, size>& args) noexcept {
		static constexpr std::size_t bits = x4::bits<T> * size;
		std::bitset<bits> result;
		for (T n : args) {
			result = (result >> x4::bits<T>) | (std::bitset<bits>(static_cast<x4::tryunsign<T>>(n)) << (bits - x4::bits<T>));
		}
		return result;
	}
}
