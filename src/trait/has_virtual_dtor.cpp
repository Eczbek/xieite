export module xieite:has_virtual_dtor;

import std;

export namespace xieite {
	template<typename T>
	concept has_virtual_dtor = std::has_virtual_destructor_v<T>;
}
