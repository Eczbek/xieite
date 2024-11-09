export module xieite:same_volat_data;

import :is_ptr;
import :is_volat;
import :set_volat_data;

export namespace xieite {
	template<typename T, xieite::is_ptr U>
	using same_volat_data = xieite::maybe_volatile<U, xieite::is_volat<T>>;
}
