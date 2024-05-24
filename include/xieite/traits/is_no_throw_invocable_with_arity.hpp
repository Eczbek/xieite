#ifndef XIEITE_HEADER_TRAITS_IS_NO_THROW_INVOCABLE_WITH_ARITY
#	define XIEITE_HEADER_TRAITS_IS_NO_THROW_INVOCABLE_WITH_ARITY

#	include <type_traits>
#	include "../concepts/no_throw_invocable_with_arity.hpp"

namespace xieite::traits {
	template<typename Functor_, std::size_t arity_>
	struct IsNoThrowInvocableWithArity
	: std::bool_constant<xieite::concepts::NoThrowInvocableWithArity<Functor_, arity_>> {};
}

#endif
