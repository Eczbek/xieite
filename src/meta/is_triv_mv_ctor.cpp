export module xieite:is_triv_mv_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv_mv_ctor = std::is_trivially_move_constructible_v<T>;
}
