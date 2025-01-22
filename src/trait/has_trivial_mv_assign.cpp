export module xieite:has_trivial_mv_assign;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_mv_assign = std::is_trivially_move_assignable_v<T>;
}
