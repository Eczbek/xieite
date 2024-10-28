export module xieite:value_const;

import std;

export namespace xieite {
	template<auto value>
	using value_const = std::integral_constant<decltype(value), value>;
}
