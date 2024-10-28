export module xieite:maybe_const;

import std;
import :copy_ref;

export namespace xieite {
	template<typename T, bool cond>
	using maybe_const = xieite::copy_ref<T, std::conditional_t<cond, const std::remove_reference_t<T>, std::remove_const_t<std::remove_reference_t<T>>>>;
}
