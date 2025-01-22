export module xieite:v;

import std;

export namespace xieite {
	template<auto x>
	using v = std::integral_constant<decltype(x), x>;
}
