export module xieite:traits.IsDerivedFromAll;

import std;
import :concepts.DerivedFromAll;

export namespace xieite::traits {
	template<typename Derived, typename... Bases>
	struct IsDerivedFromAll
	: std::bool_constant<xieite::concepts::DerivedFromAll<Derived, Bases...>> {};
}
