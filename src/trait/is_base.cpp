export module xieite:is_base;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_base = (... && std::derived_from<Us, T>);
}
