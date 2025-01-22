export module xieite:is_noex_swap;

import std;

export namespace xieite {
	template<typename T>
	concept is_noex_swap = std::is_nothrow_swappable_v<T>;
}
