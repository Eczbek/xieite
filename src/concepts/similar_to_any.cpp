export module xieite:concepts.SimilarToAny;

import :concepts.SimilarTo;

export namespace xieite::concepts {
	template<typename First, typename... Rest>
	concept SimilarToAny = (... && xieite::concepts::SimilarTo<First, Rest>);
}
