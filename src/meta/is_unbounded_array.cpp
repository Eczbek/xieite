export module xieite:is_unbounded_array;

import std;

export namespace xieite {
	template<typename T>
	concept is_unbounded_array = std::is_unbounded_array_v<T>;
}
