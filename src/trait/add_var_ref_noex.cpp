export module xieite:add_var_ref_noex;

import :add_noex;
import :add_var_ref;

export namespace xieite {
	template<typename T, typename U>
	using add_var_ref_noex = xieite::add_var_ref<T, xieite::add_noex<U>>;
}
