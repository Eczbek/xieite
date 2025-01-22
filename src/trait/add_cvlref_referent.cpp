export module xieite:add_cvlref_referent;

import :add_cv_referent;
import :add_lref_referent;

export namespace xieite {
	template<typename T>
	using add_cvlref_referent = xieite::add_cv_referent<xieite::add_lref_referent<T>>;
}
