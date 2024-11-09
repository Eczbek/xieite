export module xieite:is_nothrow_conv_from;

import :is_nothrow_conv;

export namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_conv_from = xieite::is_nothrow_conv<U, T>;
}
