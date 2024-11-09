export module xieite:is_volat;

import std;

export namespace xieite {
	template<typename T>
	concept is_volat = std::is_volatile_v<std::remove_reference_t<T>>;
}
