export module xieite:set_const_data;

import :is_ptr;
import :set_const;
import :set_ptr;

export namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using set_const_data = xieite::set_ptr<xieite::set_const<xieite::set_ptr<T, false>, cond>, true>;
}
