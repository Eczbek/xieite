export module xieite:types.LeastInteger;

import std;
import :bits.size;

export namespace xieite::types {
	template<std::size_t bits>
	using LeastInteger = std::conditional_t<(bits <= xieite::bits::size<std::uint_least8_t>), std::uint_least8_t, std::conditional_t<(bits <= xieite::bits::size<std::uint_least16_t>), std::uint_least16_t, std::conditional_t<(bits <= xieite::bits::size<std::uint_least32_t>), std::uint_least32_t, std::uint_least64_t>>>;
}

// TODO: Replace `std::conditional_t` chain with `xieite::types::List`
