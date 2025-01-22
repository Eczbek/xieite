export module xieite:set_v_referent;

import std;
import :add_v_referent;
import :rm_v_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_v_referent = std::conditional_t<qual, xieite::add_v_referent<T>, xieite::rm_v_referent<T>>;
}
