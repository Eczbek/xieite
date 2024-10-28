export module xieite:is_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept is_dtor  = std::is_destructible_v<T>;
}
