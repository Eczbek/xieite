export module xieite:is_satisfies_all;

import :is_satisfies;;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_satisfies_all = (... && xieite::is_satisfies<T, fns>);
}
