export module xieite:is_satisf;

import :is_satisfd;

export namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf = (... && xieite::is_satisfd<fns, T>);
}
