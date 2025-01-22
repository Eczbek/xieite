export module xieite:add_cvrref_referent;

import :add_cv_referent;
import :add_rref_referent;

export namespace xieite {
	template<typename T>
	using add_cvrref_referent = xieite::add_cv_referent<xieite::add_rref_referent<T>>;
}
