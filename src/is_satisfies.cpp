export module xieite:is_satisfies;

import :is_satisfied_by;

export namespace xieite {
	template<typename T, auto fn>
	concept is_satisfies = xieite::is_satisfied_by<fn, T>;
}
