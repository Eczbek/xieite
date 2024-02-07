#ifndef XIEITE_HEADER_CONCEPTS_COMPILE_TIME_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_COMPILE_TIME_INVOCABLE

#	include <concepts>
#	include <functional>

namespace xieite::detail {
	template<auto>
	constexpr bool compileTimeEvaluator = true;
}

namespace xieite::concepts {
	template<typename Functor, typename... Arguments>
	concept CompileTimeInvocable = std::invocable<Functor, Arguments...> && requires(Functor functor, Arguments... arguments) {
		xieite::detail::compileTimeEvaluator<std::invoke(functor, arguments...)>;
	};
}

#endif
