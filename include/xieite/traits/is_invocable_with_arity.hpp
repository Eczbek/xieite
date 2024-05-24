#ifndef XIEITE_HEADER_TRAITS_IS_INVOCABLE_WITH_ARITY
#	define XIEITE_HEADER_TRAITS_IS_INVOCABLE_WITH_ARITY

#	include <type_traits>
#	include "../concepts/invocable_with_arity.hpp"

namespace xieite::traits {
	template<typename Functor_, std::size_t arity_>
	struct IsInvocableWithArity
	: std::bool_constant<xieite::concepts::InvocableWithArity<Functor_, arity_>> {};
}

#endif
