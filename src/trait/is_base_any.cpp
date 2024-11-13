export module xieite:is_base_any;

import :is_base;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_base_any = (... || xieite::is_base<T, Us>);
}
