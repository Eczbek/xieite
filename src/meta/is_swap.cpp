export module xieite:is_swap;

import std;

export namespace xieite {
	template<typename T>
	concept is_swap = std::is_swappable_v<T>;
}
