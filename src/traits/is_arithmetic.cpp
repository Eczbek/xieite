export module xieite:traits.IsArithmetic;

import std;
import :concepts.Arithmetic;

export namespace xieite::traits {
	template<typename Type>
	struct IsArithmetic
	: std::bool_constant<xieite::concepts::Arithmetic<Type>> {};
}
