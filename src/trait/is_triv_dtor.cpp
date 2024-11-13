export module xieite:is_triv_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv_dtor = std::is_trivially_destructible_v<T>;
}
