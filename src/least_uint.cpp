export module xieite:least_uint;

import std;
import :bit_size;

export namespace xieite {
	template<std::size_t bits>
	using least_uint = std::conditional_t<
		(bits <= xieite::bit_size<std::uint_least8_t>),
		std::uint_least8_t,
		std::conditional_t<
			(bits <= xieite::bit_size<std::uint_least16_t>),
			std::uint_least16_t,
			std::conditional_t<
				(bits <= xieite::bit_size<std::uint_least32_t>),
				std::uint_least32_t,
				std::uint_least64_t
			>
		>
	>;
}
