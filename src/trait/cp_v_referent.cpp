export module xieite:cp_v_referent;

import std;
import :add_v_referent;
import :is_v_referent;
import :rm_v_referent;

export namespace xieite {
	template<typename T, typename U>
	using cp_v_referent = std::conditional_t<xieite::is_v_referent<T>, xieite::add_v_referent<U>, xieite::rm_v_referent<U>>;
}
