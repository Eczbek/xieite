export module xieite:rm_ref;

import std;

export namespace xieite {
	template<typename T>
	using rm_ref = std::remove_reference_t<T>;
}
