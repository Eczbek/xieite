export module xieite:is_cast_from_all;

import :is_cast_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_cast_from_all = (... && xieite::is_cast_from<T, Us>);
}
