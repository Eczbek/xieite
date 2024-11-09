export module xieite:is_dsatisf_all;

import :is_satisf_any;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf_all = !xieite::is_satisf_any<T, fns...>;
}
