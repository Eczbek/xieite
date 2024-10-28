export module xieite:is_satisfies_any;

import :is_satisfies;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_satisfies_any = (... || xieite::is_satisfies<T, fns>);
}
