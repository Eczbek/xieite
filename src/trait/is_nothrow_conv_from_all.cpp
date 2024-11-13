export module xieite:is_nothrow_conv_from_all;

import :is_nothrow_conv_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_conv_from_all = (... && xieite::is_nothrow_conv_from<T, Us>);
}
