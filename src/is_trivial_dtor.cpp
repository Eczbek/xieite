export module xieite:is_trivial_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial_dtor = std::is_trivially_destructible_v<T>;
}
