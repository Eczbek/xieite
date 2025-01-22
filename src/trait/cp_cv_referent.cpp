export module xieite:cp_cv_referent;

import :cp_c_referent;
import :cp_v_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_cv_referent = xieite::cp_c_referent<T, xieite::cp_v_referent<T, U>>;
}
