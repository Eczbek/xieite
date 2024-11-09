export module xieite:is_rm_cvref_same_any;

import :is_rm_cvref_same;

export namespace xieite {
	template<typename T, typename... Us>
	concept is_rm_cvref_same_any = (... && xieite::is_rm_cvref_same<T, Us>);
}
