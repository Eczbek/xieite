export module xieite:is_nothrow_destructible;

import std;

export namespace xieite {
	template<typename T>
	concept is_nothrow_destructible = std::is_nothrow_destructible_v<T>;
}
