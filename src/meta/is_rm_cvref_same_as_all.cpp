export module xieite:is_rm_cvref_same_as_all;

import :is_rm_cvref_same_as;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_rm_cvref_same_as_all = (... && xieite::is_rm_cvref_same_as<T, Us>);
}
