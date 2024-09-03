export module xieite:concepts.SameAsAny;

import std;

export namespace xieite::concepts {
	template<typename First, typename... Rest>
	concept SameAsAny = (... || std::same_as<First, Rest>);
}
