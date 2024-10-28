export module xieite:is_lvalue_ref;

import std;

export namespace xieite {
	template<typename T>
	concept is_lvalue_ref = std::is_lvalue_reference_v<T>;
}
