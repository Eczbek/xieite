export module xieite:add_var_cvlref;

import :add_lref_referent;
import :add_var_cv;

export namespace xieite {
	template<typename T>
	using add_var_cvlref = xieite::add_var_cv<xieite::add_lref_referent<T>>;
}
