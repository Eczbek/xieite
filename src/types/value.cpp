export module xieite:types.Value;

import std;

export namespace xieite::types {
	template<auto value>
	struct Value
	: std::integral_constant<decltype(value), value> {};
}
