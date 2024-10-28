export module xieite:value_identity;

import std;

export namespace xieite {
	template<auto value>
	using value_identity = std::integral_constant<decltype(value), value>;
}
