export module xieite:is_cast_from_any;

import :is_cast_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_cast_from_any = (... || xieite::is_cast_from<T, Us>);
}
