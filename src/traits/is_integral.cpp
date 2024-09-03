export module xieite:traits.IsIntegral;

import std;
import :concepts.Integral;

export namespace xieite::traits {
	template<typename Type>
	struct IsIntegral
	: std::bool_constant<xieite::concepts::Integral<Type>> {};
}
