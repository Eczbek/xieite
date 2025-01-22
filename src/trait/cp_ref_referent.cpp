export module xieite:cp_ref_referent;

import std;
import :add_lref_referent;
import :cp_rref_referent;
import :is_lref_referent;
import :rm_ref_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_ref_referent = std::conditional_t<xieite::is_lref_referent<T>, xieite::add_lref_referent<U>, xieite::cp_rref_referent<T, xieite::rm_ref_referent<U>>>;
}
