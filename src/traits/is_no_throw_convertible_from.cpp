export module xieite:traits.IsNoThrowConvertibleFrom;

import std;
import :concepts.NoThrowConvertibleFrom;

export namespace xieite::traits {
	template<typename Target, typename Source>
	struct IsNoThrowConvertibleFrom
	: std::bool_constant<xieite::concepts::NoThrowConvertibleFrom<Target, Source>> {};
}
