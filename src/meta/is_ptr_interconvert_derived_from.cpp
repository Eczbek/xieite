export module xieite:is_ptr_interconvert_derived_from;

import :is_ptr_interconvert_base_of;

export namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconvert_derived_from = xieite::is_ptr_interconvert_base_of<U, T>;
}
