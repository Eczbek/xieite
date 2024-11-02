export module xieite:is_trivial_default_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial_default_ctor = std::is_trivially_default_constructible_v<T>;
}
