export module xieite:is_dsatisfd_all;

import :is_satisfd_any;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd_all = !xieite::is_satisfd_any<fn, Ts...>;
}
