export module xieite:maybe_volatile;

import std;
import :copy_ref;

export namespace xieite {
	template<typename T, bool cond>
	using maybe_volatile = xieite::copy_ref<T, std::conditional_t<cond, volatile std::remove_reference_t<T>, std::remove_volatile_t<std::remove_reference_t<T>>>>;
}
