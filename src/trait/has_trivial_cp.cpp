export module xieite:has_trivial_cp;

import std;

export namespace xieite {
	template<typename T>
	concept has_trivial_cp = std::is_trivially_copyable_v<T>;
}
