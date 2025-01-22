export module xieite:is_dsatisf;

import :is_satisf_any;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf = !xieite::is_satisf_any<T, fns...>;
}
