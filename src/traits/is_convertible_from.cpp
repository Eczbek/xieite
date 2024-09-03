export module xieite:traits.IsConvertibleFrom;

import std;
import :concepts.ConvertibleFrom;

export namespace xieite::traits {
	template<typename Target, typename Source>
	struct IsConvertibleFrom
	: std::bool_constant<xieite::concepts::ConvertibleFrom<Target, Source>> {};
}
