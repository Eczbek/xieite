export module xieite:is_cp_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_cp_ctor = std::is_copy_constructible_v<T>;
}
