export module xieite:is_rvalue_ref;

import std;

export namespace xieite {
	template<typename T>
	concept is_rvalue_ref = std::is_rvalue_reference_v<T>;
}
