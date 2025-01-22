export module xieite:add_var_cvref_noex;

import :add_noex;
import :add_var_cvref;

export namespace xieite {
	template<typename T, typename U>
	using add_var_cvref_noex = xieite::add_var_cvref<T, xieite::add_noex<U>>;
}
