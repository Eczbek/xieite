export module xieite:is_virt_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept is_virt_dtor = std::has_virtual_destructor_v<T>;
}
