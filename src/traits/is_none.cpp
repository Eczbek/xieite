export module xieite:traits.IsNone;

import std;
import :concepts.None;

export namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsNone
	: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
}
