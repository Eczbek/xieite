export module xieite:traits.IsNotAll;

import std;
import :concepts.NotAll;

export namespace xieite::traits {
	template<typename Type, template<typename> typename... Traits>
	struct IsNotAll
	: std::bool_constant<xieite::concepts::NotAll<Type, Traits...>> {};
}
