export module xieite:is_noex_conv_from;

import :is_noex_conv;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_from = (... && xieite::is_noex_conv<Us, T>);
}
