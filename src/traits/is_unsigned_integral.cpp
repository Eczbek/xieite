export module xieite:traits.IsUnsignedIntegral;

import std;
import :concepts.UnsignedIntegral;

export namespace xieite::traits {
	template<typename Type>
	struct IsUnsignedIntegral
	: std::bool_constant<xieite::concepts::UnsignedIntegral<Type>> {};
}
