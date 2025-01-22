export module xieite:cp_v;

import std;
import :add_v;
import :is_v;
import :rm_v;

export namespace xieite {
	template<typename T, typename U>
	using cp_v = std::conditional_t<xieite::is_v<T>, xieite::add_v<U>, xieite::rm_v<U>>;
}
