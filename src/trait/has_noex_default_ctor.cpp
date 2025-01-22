export module xieite:has_noex_default_ctor;

import std;

export namespace xieite {
	template<typename T>
	concept has_noex_default_ctor = std::is_nothrow_default_constructible_v<T>;
}
