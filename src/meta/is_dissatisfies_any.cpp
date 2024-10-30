export module xieite:is_dissatisfies_any;

import :is_satisfies_all;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_dissatisfies_any = !xieite::is_satisfies_all<T, fns...>;
}
