export module xieite:traits.IsDecayed;

import std;
import :concepts.Decayed;

export namespace xieite::traits {
	template<typename Type>
	struct IsDecayed
	: std::bool_constant<xieite::concepts::Decayed<Type>> {};
}
