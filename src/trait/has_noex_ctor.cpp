export module xieite:has_noex_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_noex_ctor = std::is_nothrow_constructible_v<T>;
}
