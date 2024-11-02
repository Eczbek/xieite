export module xieite:is_virt_derived_from;

import std;
import :is_virt_base_of;

export namespace xieite {
	template<typename T, typename U>
	concept is_virt_derived_from = xieite::is_virt_base_of<U, T>;
}
