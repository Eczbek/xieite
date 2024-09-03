export module xieite:traits.IsAll;

import std;
import :concepts.All;

export namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsAll
	: std::bool_constant<xieite::concepts::All<Type, Traits...>> {};
}
