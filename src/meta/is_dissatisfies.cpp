export module xieite:is_dissatisfies;

import :is_satisfies;

export namespace xieite {
	template<typename T, auto fn>
	concept is_dissatisfies = !xieite::is_satisfies<T, fn>;
}
