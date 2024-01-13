#ifndef XIEITE_HEADER_TRAITS_IS_CONSTANT_INVOCABLE
#	define XIEITE_HEADER_TRAITS_IS_CONSTANT_INVOCABLE

#	include <type_traits>
#	include "../concepts/constant_invocable.hpp"

namespace xieite::concepts {
	template<typename Functor, typename... Arguments>
	struct IsConstantInvocable
	: std::bool_constant<xieite::concepts::ConstantInvocable<Functor, Arguments...>> {};
}

#endif
