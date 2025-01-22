export module xieite:has_mv_assign;

import std;

export namespace xieite {
	template<typename T>
	concept has_mv_assign = std::is_move_assignable_v<T>;
}
