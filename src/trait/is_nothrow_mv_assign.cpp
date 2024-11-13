export module xieite:is_nothrow_mv_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_mv_assign = std::is_nothrow_move_assignable_v<T>;
}
