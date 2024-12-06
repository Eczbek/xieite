export module xieite:is_dissatisfied_any;

import :is_satisfd_any;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_any = !xieite::is_satisfd_any<fn, Ts...>;
}
