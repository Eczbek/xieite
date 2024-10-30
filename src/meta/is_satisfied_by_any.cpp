export module xieite:is_satisfied_by_any;

import :is_satisfied_by;

export namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfied_by_any = (... || xieite::is_satisfied_by<fn, Ts>);
}
