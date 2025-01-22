export module xieite:has_trivial_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_dtor = std::is_trivially_destructible_v<T>;
}
