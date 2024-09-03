export module xieite:traits.IsConvertibleTo;

import std;

export namespace xieite::traits {
	template<typename Source, typename Target>
	struct IsConvertibleTo
	: std::bool_constant<std::convertible_to<Source, Target>> {};
}
