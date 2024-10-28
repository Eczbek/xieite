export module xieite:copy_volatile_data;

import :is_ptr;
import :is_volatile;
import :maybe_volatile_data;

export namespace xieite {
	template<typename T, xieite::is_ptr U>
	using copy_volatile_data = xieite::maybe_volatile<U, xieite::is_volatile<T>>;
}
