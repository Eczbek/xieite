export module xieite:traits.IsDerivedFromAny;

import std;
import :concepts.DerivedFromAny;

export namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct IsDerivedFromAny
	: std::bool_constant<xieite::concepts::DerivedFromAny<Derived, Bases...>> {};
}
