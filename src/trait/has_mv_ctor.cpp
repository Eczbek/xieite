export module xieite:has_mv_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_mv_ctor = std::is_move_constructible_v<T>;
}
