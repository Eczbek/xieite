export module xieite:collapse_ref;

import std;
import :copy_const;
import :copy_volatile;

export namespace xieite {
	template<typename T, typename U>
	using collapse_ref = xieite::copy_volatile<T, xieite::copy_const<T, std::conditional_t<std::is_lvalue_reference_v<T>, std::add_lvalue_reference_t<U>, std::add_rvalue_reference_t<U>>>>;
}
