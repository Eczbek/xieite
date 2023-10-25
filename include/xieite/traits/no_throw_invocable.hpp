#ifndef XIEITE_HEADER_TRAITS_NO_THROW_INVOCABLE
#	define XIEITE_HEADER_TRAITS_NO_THROW_INVOCABLE

#	include <type_traits>
#	include "../concepts/no_throw_invocable.hpp"

namespace xieite::traits {
	template<typename Functor, typename... Arguments>
	struct NoThrowInvocable
	: std::bool_constant<xieite::concepts::NoThrowInvocable<Functor, Arguments...>> {};
}

#endif
