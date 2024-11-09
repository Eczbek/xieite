export module xieite:same_mv_ctor;

import std;
import :set_mv_ctor;

export namespace xieite {
	template<typename T>
	using same_mv_ctor = xieite::set_mv_ctor<std::is_move_constructible_v<T>>;
}
