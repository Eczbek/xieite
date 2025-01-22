export module xieite:set_v;

import std;
import :add_v;
import :rm_v;

export namespace xieite {
	template<bool qual, typename T>
	using set_v = std::conditional_t<qual, xieite::add_v<T>, xieite::rm_v<T>>;
}
