export module xieite:is_trivial_move_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial_move_ctor = std::is_trivially_move_constructible_v<T>;
}
