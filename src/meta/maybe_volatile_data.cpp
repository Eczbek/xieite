export module xieite:maybe_volatile_data;

import :is_ptr;
import :maybe_ptr;
import :maybe_volatile;

export namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using maybe_volatile_data = xieite::maybe_ptr<xieite::maybe_volatile<xieite::maybe_ptr<T, false>, cond>, true>;
}
