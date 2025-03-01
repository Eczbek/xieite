#pragma once

#include <cstddef>
#include <cstdint>
#include "../math/bits.hpp"
#include "../meta/typel.hpp"

namespace x4 {
	template<std::size_t bits>
	using uleast = x4::typel<
		std::uint_least8_t,
		std::uint_least16_t,
		std::uint_least32_t,
		std::uint_least64_t
	>::find<[]<typename T> requires(x4::bits<T> >= bits) {}>;
}
