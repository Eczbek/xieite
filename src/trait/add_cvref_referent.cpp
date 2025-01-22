export module xieite:add_cvref_referent;

import :add_cv_referent;
import :add_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using add_cvref_referent = xieite::add_cv_referent<xieite::add_ref_referent<T, U>>;
}
