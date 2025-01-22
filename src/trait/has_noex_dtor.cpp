export module xieite:has_noex_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept has_noex_dtor = std::is_nothrow_destructible_v<T>;
}
