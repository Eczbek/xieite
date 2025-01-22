export module xieite:is_derived_from;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from = (... && std::derived_from<T, Us>);
}
