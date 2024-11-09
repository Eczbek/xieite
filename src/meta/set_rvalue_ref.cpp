export module xieite:set_rvalue_ref;

import std;

export namespace xieite {
	template<typename T, bool cond>
	using set_rvalue_ref = std::conditional_t<cond, std::add_rvalue_reference_t<std::remove_reference_t<T>>, std::remove_reference_t<T>>;
}
