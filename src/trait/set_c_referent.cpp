export module xieite:set_c_referent;

import std;
import :add_c_referent;
import :rm_c_referent;

export namespace xieite {
	template<bool qual, typename T>
	using set_c_referent = std::conditional_t<qual, xieite::add_c_referent<T>, xieite::rm_c_referent<T>>;
}
