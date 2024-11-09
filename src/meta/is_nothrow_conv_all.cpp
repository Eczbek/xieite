export module xieite:is_nothrow_conv_all;

import :is_nothrow_conv;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_conv_all = (... && xieite::is_nothrow_conv<T, Us>);
}
