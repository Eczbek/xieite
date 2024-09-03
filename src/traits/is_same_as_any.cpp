export module xieite:traits.IsSameAsAny;

import std;
import :concepts.SameAsAny;

export namespace xieite::traits {
	template<typename First, typename... Rest>
	struct IsSameAsAny
	: std::bool_constant<xieite::concepts::SameAsAny<First, Rest...>> {};
}
