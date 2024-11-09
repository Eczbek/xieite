export module xieite:is_ptr_interconv_deriv;

import :is_ptr_interconv_base;

export namespace xieite {
	template<typename T, typename U>
	concept is_ptr_interconv_deriv = xieite::is_ptr_interconv_base<U, T>;
}
