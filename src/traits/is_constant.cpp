export module xieite:traits.IsConstant;

import std;
import :concepts.Constant;

export namespace xieite::traits {
	template<typename Type>
	struct IsConstant
	: std::bool_constant<xieite::concepts::Constant<Type>> {};
}
