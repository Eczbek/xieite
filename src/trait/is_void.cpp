export module xieite:is_void;

import std;

export namespace xieite {
	template<typename T>
	concept is_void = std::is_void_v<T>;
}
