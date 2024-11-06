export module xieite:same_move_ctor;

import std;
import :maybe_move_ctor;

export namespace xieite {
	template<typename T>
	using same_move_ctor = xieite::maybe_move_ctor<std::is_move_constructible_v<T>>;
}
