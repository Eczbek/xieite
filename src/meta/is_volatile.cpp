export module xieite:is_volatile;

import std;

export namespace xieite {
	template<typename T>
	concept is_volatile = std::is_volatile_v<std::remove_reference_t<T>>;
}
