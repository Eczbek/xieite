export module xieite:is_union;

import std;

export namespace xieite {
	template<typename T>
	concept is_union = std::is_union_v<T>;
}
