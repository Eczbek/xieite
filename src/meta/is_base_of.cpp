export module xieite:is_base_of;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_base_of = std::derived_from<U, T>;
}
