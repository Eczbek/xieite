export module xieite:is_bounded_array;

import std;

export namespace xieite {
	template<typename T>
	concept is_bounded_array = std::is_bounded_array_v<T>;
}
