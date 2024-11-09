export module xieite:same_ref;

import std;

export namespace xieite {
	template<typename T, typename U>
	using same_ref = std::conditional_t<std::is_lvalue_reference_v<T>, std::add_lvalue_reference_t<std::remove_reference_t<U>>, std::conditional_t<std::is_rvalue_reference_v<T>, std::add_rvalue_reference_t<std::remove_reference_t<U>>, std::remove_reference_t<U>>>;
}
