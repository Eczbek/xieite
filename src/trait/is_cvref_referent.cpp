export module xieite:is_cvref_referent;

import :is_cvlref_referent;
import :is_cvrref_referent;

export namespace xieite {
	template<typename T>
	concept is_cvref_referent = xieite::is_cvlref_referent<T> || xieite::is_cvrref_referent<T>;
}
