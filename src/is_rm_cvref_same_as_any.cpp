export module xieite:is_remove_cvref_same_as_any;

import :is_remove_cvref_same_as;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_remove_cvref_same_as_any = (... && xieite::is_remove_cvref_same_as<T, Us>);
}