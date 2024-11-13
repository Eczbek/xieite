export module xieite:is_satisfd_all;

import :is_satisfd;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd_all = (... && xieite::is_satisfd<fn, Ts>);
}
