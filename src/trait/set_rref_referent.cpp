export module xieite:set_rref_referent;

import std;
import :add_rref_referent;
import :rm_rref_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_rref_referent = std::conditional_t<qual, xieite::add_rref_referent<T>, xieite::rm_rref_referent<T>>;
}
