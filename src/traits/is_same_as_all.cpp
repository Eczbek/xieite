export module xieite:traits.IsSameAsAll;

import std;
import :concepts.SameAsAll;

export namespace xieite::traits {
	template<typename First, typename... Rest>
	struct IsSameAsAll
	: std::bool_constant<xieite::concepts::SameAsAll<First, Rest...>> {};
}
