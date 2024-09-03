export module xieite:traits.IsConvertibleFromAll;

import std;
import :concepts.ConvertibleFromAll;

export namespace xieite::traits {
	template<typename Target, typename... Sources>
	struct IsConvertibleFromAll
	: std::bool_constant<xieite::concepts::ConvertibleFromAll<Target, Sources...>> {};
}
