export module xieite:is_conv_to_any;

import :is_conv_to;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_to_any = (... || xieite::is_conv_to<T, Us>);
}
