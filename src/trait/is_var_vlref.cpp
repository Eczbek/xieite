export module xieite:is_var_vlref;

import :is_lref_referent;
import :is_var_v;

export namespace xieite {
	template<typename T>
	concept is_var_vlref = xieite::is_var_v<T> && xieite::is_lref_referent<T>;
}
