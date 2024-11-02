export module xieite:is_array;

import std;

export namespace xieite {
	template<typename T>
	concept is_array = std::is_array_v<T>;
}
