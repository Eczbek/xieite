export module xieite:is_convertible_from_any;

import :is_convertible_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_convertible_from_any = (... || xieite::is_convertible_from<T, Us>);
}
