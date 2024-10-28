export module xieite:maybe_const_data;

import :is_ptr;
import :maybe_const;
import :maybe_ptr;

export namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using maybe_const_data = xieite::maybe_ptr<xieite::maybe_const<xieite::maybe_ptr<T, false>, cond>, true>;
}
