export module xieite:is_dissatisfied_by_all;

import :is_satisfied_by_any;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_by_all = !xieite::is_satisfied_by_any<fn, Ts...>;
}
