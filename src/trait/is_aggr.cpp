export module xieite:is_aggr;

import std;

export namespace xieite {
	template<typename T>
	concept is_aggr = std::is_aggregate_v<T>;
}
