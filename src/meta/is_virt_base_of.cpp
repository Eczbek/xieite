export module xieite:is_virt_base_of;

import std;

export namespace xieite {
	template<typename T, typename U>
	concept is_virt_base_of = std::is_virtual_base_of_v<T, U>;
}
