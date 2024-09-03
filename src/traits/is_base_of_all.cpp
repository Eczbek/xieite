export module xieite:traits.IsBaseOfAll;

import std;
import :concepts.BaseOfAll;

export namespace xieite::traits {
	template<typename Base, typename... Derived>
	struct IsBaseOfAll
	: std::bool_constant<xieite::concepts::BaseOfAll<Base, Derived...>> {};
}
