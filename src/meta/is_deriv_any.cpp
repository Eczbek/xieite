export module xieite:is_derived_from_any;

import std;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from_any = (... || std::derived_from<T, Us>);
}
