export module xieite:set_var;

import std;
import :add_var;
import :rm_var;

export namespace xieite {
	template<bool qual, typename T>
	using set_var = std::conditional_t<qual, xieite::add_var<T>, xieite::rm_var<T>>;
}
