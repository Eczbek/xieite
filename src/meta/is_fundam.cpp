export module xieite:is_fundam;

import std;

export namespace xieite {
	template<typename T>
	concept is_fundam = std::is_fundamental_v<T>;
}
