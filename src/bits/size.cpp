export module xieite:bits.size;

import std;

export namespace xieite::bits {
	template<typename Type>
	constexpr std::size_t size = sizeof(Type) * std::numeric_limits<unsigned char>::digits;

	template<std::integral Integral>
	constexpr std::size_t size<Integral> = std::numeric_limits<Integral>::digits + std::numeric_limits<Integral>::is_signed;
}

// After a long and very intense debate between FOUR different wizards on several topics of varying relativity, it was deemed that `std::numeric_limits<unsigned char>::digits` and `CHAR_BIT` both are terrible options and there's no good way of doing anything at all
