export module xieite:is_nothrow_conv_any;

import :is_nothrow_conv;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_conv_any = (... || xieite::is_nothrow_conv<T, Us>);
}
