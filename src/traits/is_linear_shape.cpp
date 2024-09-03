export module xieite:traits.IsLinearShape;

import std;
import :concepts.LinearShape;

export namespace xieite::traits {
	template<typename Type>
	struct IsLinearShape
	: std::bool_constant<xieite::concepts::LinearShape<Type>> {};
}
