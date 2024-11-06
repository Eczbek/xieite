export module xieite:is_nothrow_cast_to_any;

import :is_nothrow_cast_to;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_cast_to_any = (... || xieite::is_nothrow_cast_to<T, Us>);
}
