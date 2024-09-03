export module xieite:traits.IsBitsetReference;

import std;
import :concepts.BitsetReference;

export namespace xieite::traits {
	template<typename Type>
	struct IsBitsetReference
	: std::bool_constant<xieite::concepts::BitsetReference<Type>> {};
}
