export module xieite:set_volat;

import std;
import :same_ref;

export namespace xieite {
	template<typename T, bool cond>
	using set_volat = xieite::same_ref<T, std::conditional_t<cond, volatile std::remove_reference_t<T>, std::remove_volatile_t<std::remove_reference_t<T>>>>;
}
