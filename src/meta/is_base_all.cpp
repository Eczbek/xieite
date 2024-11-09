export module xieite:is_base_all;

import :is_base;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_base_all = (... && xieite::is_base<T, Us>);
}
