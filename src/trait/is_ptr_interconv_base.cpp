export module xieite:is_ptr_interconv_base;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconv_base = std::is_pointer_interconvertible_base_of_v<T, U>;
}
