export module xieite:is_nothrow_swap;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_swap = std::is_nothrow_swappable_v<T>;
}
