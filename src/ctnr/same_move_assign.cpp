export module xieite:same_move_assign;

import std;
import :maybe_move_assign;

export namespace xieite {
	template<typename T>
	using same_move_assign = xieite::maybe_move_assign<std::is_move_assignable_v<T>>;
}
