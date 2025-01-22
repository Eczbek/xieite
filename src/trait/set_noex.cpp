export module xieite:set_noex;

import :add_noex;
import :rm_noex;

export namespace xieite {
	template<bool qual, typename T>
	using set_noex = std::conditional_t<qual, xieite::add_noex<T>, xieite::rm_noex<T>>;
}
