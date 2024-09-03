export module xieite:types.TrySigned;

import std;
import :concepts.UnsignedIntegral;

export namespace xieite::types {
	template<typename Type>
	using TrySigned = std::conditional_t<xieite::concepts::UnsignedIntegral<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
}
