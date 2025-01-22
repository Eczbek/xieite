export module xieite:has_default_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_default_ctor = std::is_default_constructible_v<T>;
}
