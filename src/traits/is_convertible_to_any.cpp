export module xieite:traits.IsConvertibleToAny;

import std;
import :concepts.ConvertibleToAny;

export namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsConvertibleToAny
	: std::bool_constant<xieite::concepts::ConvertibleToAny<Source, Targets...>> {};
}
