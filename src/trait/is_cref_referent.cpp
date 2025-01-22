export module xieite:is_cref_referent;

import :is_clref_referent;
import :is_crref_referent;

export namespace xieite {
	template<typename T>
	concept is_cref_referent = xieite::is_clref_referent<T> || xieite::is_crref_referent<T>;
}
