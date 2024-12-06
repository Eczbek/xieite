export module xieite:is_satisf;

import :is_satisfd;

export namespace xieite {
	template<typename T, auto fn>
	concept is_satisf = xieite::is_satisfd<fn, T>;
}
