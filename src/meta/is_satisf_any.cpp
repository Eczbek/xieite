export module xieite:is_satisf_any;

import :is_satisf;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf_any = (... || xieite::is_satisf<T, fns>);
}
