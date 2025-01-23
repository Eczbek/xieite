export module xieite:has_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_ctor = std::is_constructible_v<T>;
}
