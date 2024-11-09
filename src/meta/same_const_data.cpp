export module xieite:same_const_data;

import :is_const;
import :is_ptr;
import :set_const_data;

export namespace xieite {
	template<typename T, xieite::is_ptr U>
	using same_const_data = xieite::set_const_data<U, xieite::is_const<T>>;
}
