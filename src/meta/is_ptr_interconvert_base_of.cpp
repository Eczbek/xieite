export module xieite:is_ptr_interconvert_base_of;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconvert_base_of = std::is_pointer_interconvertible_base_of_v<T, U>;
}
