export module xieite:is_dsatisf;

import :is_satisf;

export namespace xieite {
	template<typename T, auto fn>
	concept is_dsatisf = !xieite::is_satisf<T, fn>;
}
