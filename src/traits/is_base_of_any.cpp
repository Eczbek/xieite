export module xieite:traits.IsBaseOfAny;

import std;
import :concepts.BaseOfAny;

export namespace xieite::traits {
	template<typename Base, typename... Derived>
	struct IsBaseOfAny
	: std::bool_constant<xieite::concepts::BaseOfAny<Base, Derived...>> {};
}
