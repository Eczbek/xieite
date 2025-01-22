export module xieite:is_rref;

import std;

export namespace xieite {
	template<typename T>
	concept is_rref = std::is_rvalue_reference_v<T>;
}
