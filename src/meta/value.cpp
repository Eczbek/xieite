export module xieite:value;

import std;

export namespace xieite {
	template<auto value_>
	using value = std::integral_constant<decltype(value_), value_>;
}
