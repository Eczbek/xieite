export module xieite:types.TryUnsigned;

import std;

export namespace xieite::types {
	template<typename Type>
	using TryUnsigned = std::conditional_t<std::signed_integral<Type>, std::make_unsigned<Type>, std::type_identity<Type>>::type;
}
