export module xieite:traits.IsBaseOf;

import std;
import :concepts.BaseOf;

export namespace xieite::traits {
	template<typename Base, typename Derived>
	struct IsBaseOf
	: std::bool_constant<xieite::concepts::BaseOf<Base, Derived>> {};
}
