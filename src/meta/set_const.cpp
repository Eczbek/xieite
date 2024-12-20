export module xieite:set_const;

import std;
import :same_ref;

export namespace xieite {
	template<typename T, bool cond>
	using set_const = xieite::same_ref<T, std::conditional_t<cond, const std::remove_reference_t<T>, std::remove_const_t<std::remove_reference_t<T>>>>;
}
