export module xieite:has_trivial_cp_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_cp_ctor = std::is_trivially_copy_constructible_v<T>;
}
