#ifndef XIEITE_HEADER_TRAITS_IS_INVOCABLE_WITH_ARITY
#	define XIEITE_HEADER_TRAITS_IS_INVOCABLE_WITH_ARITY

#	include <type_traits>
#	include "../concepts/invocable_with_arity.hpp"

namespace xieite::traits {
	template<typename Functor, std::size_t arity>
	struct IsInvocableWithArity
	: std::bool_constant<xieite::concepts::InvocableWithArity<Functor, arity>> {};
}

#endif
