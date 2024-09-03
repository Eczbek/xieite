export module xieite:traits.IsSimilarTo;

import std;
import :concepts.SimilarTo;

export namespace xieite::traits {
	template<typename First, typename Second>
	struct IsSimilarTo
	: std::bool_constant<xieite::concepts::SimilarTo<First, Second>> {};
}
