export module xieite:is_noex_swap_with;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_noex_swap_with = std::is_nothrow_swappable_with_v<T, U>;
}
