export module xieite:has_trivial_default_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_default_ctor = std::is_trivially_default_constructible_v<T>;
}
