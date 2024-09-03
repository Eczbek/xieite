export module xieite:concepts.SimilarToAll;

import :concepts.SimilarTo;

export namespace xieite::concepts {
	template<typename First, typename... Rest>
	concept SimilarToAll = (... && xieite::concepts::SimilarTo<First, Rest>);
}
