export module xieite:add_var_cvref;

import :add_ref_referent;
import :add_var_cv;

export namespace xieite {
	template<typename T, typename U>
	using add_var_cvref = xieite::add_var_cv<xieite::add_ref_referent<T, U>>;
}
