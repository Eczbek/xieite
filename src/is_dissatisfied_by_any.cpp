export module xieite:is_dissatisfied_by_any;

import :is_satisfied_by_all;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_by_any = !xieite::is_satisfied_by_all<fn, Ts...>;
}
