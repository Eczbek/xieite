export module xieite:is_remove_cvref_same_as_all;

import :is_remove_cvref_same_as;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_remove_cvref_same_as_all = (... && xieite::is_remove_cvref_same_as<T, Us>);
}
