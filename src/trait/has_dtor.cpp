export module xieite:has_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept has_dtor  = std::is_destructible_v<T>;
}
