export module xieite:is_dissatisfies_all;

import :is_satisfies_any;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_dissatisfies_all = !xieite::is_satisfies_any<T, fns...>;
}
