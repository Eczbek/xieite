export module xieite:cp_mv_assign;

import std;
import :set_mv_assign;

export namespace xieite {
	template<typename T>
	using cp_mv_assign = xieite::set_mv_assign<std::is_move_assignable_v<T>>;
}
