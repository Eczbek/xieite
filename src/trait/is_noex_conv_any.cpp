export module xieite:is_noex_conv_any;

import :is_noex_conv;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_any = (... || xieite::is_noex_conv<T, Us>);
}
