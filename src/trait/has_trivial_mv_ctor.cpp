export module xieite:has_trivial_mv_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_mv_ctor = std::is_trivially_move_constructible_v<T>;
}
