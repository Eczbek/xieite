export module xieite:is_ptr;

import std;

export namespace xieite {
	template<typename T>
	concept is_ptr = std::is_pointer_v<std::remove_reference_t<T>>;
}
