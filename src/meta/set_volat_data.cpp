export module xieite:set_volat_data;

import :is_ptr;
import :set_ptr;
import :set_volat;

export namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using set_volat_data = xieite::set_ptr<xieite::set_volat<xieite::set_ptr<T, false>, cond>, true>;
}
