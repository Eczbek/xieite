export module xieite:same_move_assignable;

import std;
import :maybe_move_assignable;

export namespace xieite {
	template<typename T>
	using same_move_assignable = xieite::maybe_move_assignable<std::is_move_assignable_v<T>>;
}
