export module xieite:is_dsatisfd;

import :is_satisfd;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd = !xieite::is_satisfd<fn, Ts...>;
}
