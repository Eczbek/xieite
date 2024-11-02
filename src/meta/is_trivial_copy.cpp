export module xieite:is_trivial_copy;

import std;

export namespace xieite {
	template<typename T>
	concept is_trivial_copy = std::is_trivially_copyable_v<T>;
}
