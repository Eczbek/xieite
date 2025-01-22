export module xieite:add_cv_noex;

import :add_cv_referent;
import :add_noex;

export namespace xieite {
	template<typename T>
	using add_cv_noex = xieite::add_cv_referent<xieite::add_noex<T>>;
}
