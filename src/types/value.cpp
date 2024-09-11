export module xieite:types.Value;

import std;

export namespace xieite::types {
	template<auto value>
	using Value = std::integral_constant<decltype(value), value>;
}
