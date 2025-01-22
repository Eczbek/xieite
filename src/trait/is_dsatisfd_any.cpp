export module xieite:is_dsatisfd_any;

import :is_satisfd_all;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd_any = !xieite::is_satisfd_all<fn, Ts...>;
}
