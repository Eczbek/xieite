export module xieite:collapse_ref;

import std;
import :same_const;
import :same_volat;

export namespace xieite {
	template<typename T, typename U>
	using collapse_ref = xieite::same_volat<T, xieite::same_const<T, std::conditional_t<std::is_lvalue_reference_v<T>, std::add_lvalue_reference_t<U>, std::add_rvalue_reference_t<U>>>>;
}
