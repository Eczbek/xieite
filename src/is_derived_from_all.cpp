export module xieite:is_derived_from_all;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from_all = (... && std::derived_from<T, Us>);
}
