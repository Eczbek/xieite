export module xieite:is_triv_mv_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv_mv_assign = std::is_trivially_move_assignable_v<T>;
}
