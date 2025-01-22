export module xieite:is_dsatisf_any;

import :is_satisf;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf_any = !xieite::is_satisf<T, fns...>;
}
