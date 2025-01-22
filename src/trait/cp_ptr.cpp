export module xieite:cp_ptr;

import :add_ptr;
import :get_ptr;
import :rm_ptr;

export namespace xieite {
	template<typename T, typename U>
	using cp_ptr = xieite::add_ptr<xieite::get_ptr<T>, xieite::rm_ptr<U>>;
}
