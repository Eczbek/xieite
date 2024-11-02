export module xieite:is_trivial_copy_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial_copy_ctor = std::is_trivially_copy_constructible_v<T>;
}
