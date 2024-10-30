export module xieite:is_dissatisfied_by;

import :is_satisfied_by;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_by = !xieite::is_satisfied_by<fn, Ts...>;
}
