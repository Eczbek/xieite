export module xieite:same_move_constructible;

import std;
import :maybe_move_constructible;

export namespace xieite {
	template<typename T>
	using same_move_constructible = xieite::maybe_move_constructible<std::is_move_constructible_v<T>>;
}
