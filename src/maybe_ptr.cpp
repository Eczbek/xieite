export module xieite:maybe_ptr;

import std;
import :copy_ref;

export namespace xieite {
	template<typename T, bool cond>
	using maybe_ptr = xieite::copy_ref<T, std::conditional_t<cond, std::remove_pointer_t<std::remove_reference_t<T>>*, std::remove_pointer_t<std::remove_reference_t<T>>>>;
}