export module xieite:maybe_lvalue_ref;

import std;

export namespace xieite {
	template<typename T, bool cond>
	using maybe_lvalue_ref = std::conditional_t<cond, std::add_lvalue_reference_t<std::remove_reference_t<T>>, std::remove_reference_t<T>>;
}
