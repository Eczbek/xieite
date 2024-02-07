#ifndef XIEITE_HEADER_TRAITS_IS_COMPILE_TIME_EVALUABLE
#	define XIEITE_HEADER_TRAITS_IS_COMPILE_TIME_EVALUABLE

#	include <type_traits>
#	include "../concepts/compile_time_evaluable.hpp"

namespace xieite::traits {
	template<typename Functor, typename... Arguments>
	struct IsCompileTimeInvocable
	: std::bool_constant<xieite::concepts::CompileTimeInvocable<Functor, Arguments...>> {};
}

#endif
