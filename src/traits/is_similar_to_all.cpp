export module xieite:traits.IsSimilarToAll;

import std;
import :concepts.SimilarToAll;

export namespace xieite::traits {
	template<typename First, typename... Rest>
	struct IsSimilarToAll
	: std::bool_constant<xieite::concepts::SimilarToAll<First, Rest...>> {};
}
