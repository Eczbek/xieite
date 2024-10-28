export module xieite:is_nothrow_cast_from;

import :is_nothrow_convertible_to;

export namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_cast_from = xieite::is_nothrow_cast_to<U, T>;
}
