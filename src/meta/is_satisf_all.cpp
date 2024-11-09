export module xieite:is_satisf_all;

import :is_satisf;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf_all = (... && xieite::is_satisf<T, fns>);
}
