export module xieite:add_cv_referent;

import :add_c_referent;
import :add_v_referent;

export namespace xieite {
	template<typename T>
	using add_cv_referent = xieite::add_c_referent<xieite::add_v_referent<T>>;
}
