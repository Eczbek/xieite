export module xieite:traits.IsSimilarToAny;

import std;
import :concepts.SimilarToAny;

export namespace xieite::traits {
	template<typename First, typename... Rest>
	struct IsSimilarToAny
	: std::bool_constant<xieite::concepts::SimilarToAny<First, Rest...>> {};
}
