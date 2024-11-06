export module xieite:is_trivial_assign;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_trivial_assign = std::is_trivially_assignable_v<T, U>;
}
