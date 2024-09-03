export module xieite:concepts.SameAsAll;

import std;

export namespace xieite::concepts {
	template<typename First, typename... Rest>
	concept SameAsAll = (... || std::same_as<First, Rest>);
}
