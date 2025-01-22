export module xieite:has_trivial_assign;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept has_trivial_assign = std::is_trivially_assignable_v<T, U>;
}
