export module xieite:concepts.Aggregate;

import std;

export namespace xieite::concepts {
	template<typename Type>
	concept Aggregate = std::is_aggregate_v<Type>;
}
