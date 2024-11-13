export module xieite:is_base;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_base = std::derived_from<U, T>;
}
