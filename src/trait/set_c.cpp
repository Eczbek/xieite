export module xieite:set_c;

import std;
import :add_c;
import :rm_c;

export namespace xieite {
	template<bool qual, typename T>
	using set_c = std::conditional_t<qual, xieite::add_c<T>, xieite::rm_c<T>>;
}
