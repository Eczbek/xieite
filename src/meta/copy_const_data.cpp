export module xieite:copy_const_data;

import :is_const;
import :is_ptr;
import :maybe_const_data;

export namespace xieite {
	template<typename T, xieite::is_ptr U>
	using copy_const_data = xieite::maybe_const_data<U, xieite::is_const<T>>;
}
