export module xieite:is_triv_cp_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv_cp_ctor = std::is_trivially_copy_constructible_v<T>;
}
