export module xieite:is_noex_conv_from_any;

import :is_noex_conv_from;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_from_any = (... && xieite::is_noex_conv_from<T, Us>);
}
