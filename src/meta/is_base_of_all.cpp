export module xieite:is_base_of_all;

import :is_base_of;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_base_of_all = (... && xieite::is_base_of<T, Us>);
}
