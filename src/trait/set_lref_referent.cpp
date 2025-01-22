export module xieite:set_lref_referent;

import std;
import :add_lref_referent;
import :rm_lref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_lref_referent = std::conditional_t<qual, xieite::add_lref_referent<T>, xieite::rm_lref_referent<T>>;
}
