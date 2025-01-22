export module xieite:is_derived_from_any;

import :is_derived_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_derived_from_any = (... || xieite::is_derived_from<T, Us>);
}
