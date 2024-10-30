export module xieite:is_convertible_from_all;

import :is_convertible_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_convertible_from_all = (... && xieite::is_convertible_from<T, Us>);
}
