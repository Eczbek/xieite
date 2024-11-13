export module xieite:is_triv_cp;

import std;

export namespace xieite {
	template<typename T>
	concept is_triv_cp = std::is_trivially_copyable_v<T>;
}
