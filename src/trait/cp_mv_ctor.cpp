export module xieite:cp_mv_ctor;

import std;
import :set_mv_ctor;

export namespace xieite {
	template<typename T>
	using cp_mv_ctor = xieite::set_mv_ctor<std::is_move_constructible_v<T>>;
}
