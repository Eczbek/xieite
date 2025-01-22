export module xieite:is_swap_with;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_swap_with = std::is_swappable_with_v<T, U>;
}
