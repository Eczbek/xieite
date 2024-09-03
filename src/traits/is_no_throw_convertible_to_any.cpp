export module xieite:traits.IsNoThrowConvertibleToAny;

import std;
import :concepts.NoThrowConvertibleToAny;

export namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToAny
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source, Targets...>> {};
}
