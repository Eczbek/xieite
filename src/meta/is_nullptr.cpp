export module xieite:is_nullptr;

import std;

export namespace xieite {
	template<typename T>
	concept is_nullptr = std::is_null_pointer_v<T>;
}
