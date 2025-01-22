export module xieite:is_ref_referent;

import :is_lref_referent;
import :is_rref_referent;

export namespace xieite {
	template<typename T>
	concept is_ref_referent = xieite::is_lref_referent<T> || xieite::is_rref_referent<T>;
}
