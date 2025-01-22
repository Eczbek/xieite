export module xieite:is_lref;

import std;

export namespace xieite {
	template<typename T>
	concept is_lref = std::is_lvalue_reference_v<T>;
}
