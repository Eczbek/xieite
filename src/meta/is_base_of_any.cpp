export module xieite:is_base_of_any;

import :is_base_of;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_base_of_any = (... || xieite::is_base_of<T, Us>);
}
