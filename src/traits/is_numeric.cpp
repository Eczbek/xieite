export module xieite:traits.IsNumeric;

import std;
import :concepts.Numeric;

export namespace xieite::traits {
	template<typename Type>
	struct IsNumeric
	: std::bool_constant<xieite::concepts::Numeric<Type>> {};
}
