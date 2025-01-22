export module xieite:add_lref;

import std;

export namespace xieite {
	template<typename T>
	using add_lref = std::add_lvalue_reference_t<T>;
}
