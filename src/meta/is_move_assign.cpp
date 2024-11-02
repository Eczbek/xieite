export module xieite:is_move_assign;

import std;

export namespace xieite {
	template<typename T>
	concept is_move_assign = std::is_move_assignable_v<T>;
}
