export module xieite:add_rref;

import std;

export namespace xieite {
	template<typename T>
	using add_rref = std::add_rvalue_reference_t<T>;
}
