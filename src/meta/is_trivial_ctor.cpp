export module xieite:is_trivial_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial_ctor = std::is_trivially_constructible_v<T>;
}
