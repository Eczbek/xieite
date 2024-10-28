export module xieite:is_nothrow_cast_to_all;

import :is_nothrow_convertible_to;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_cast_to_all = (... && xieite::is_nothrow_cast_to<T, Us>);
}
