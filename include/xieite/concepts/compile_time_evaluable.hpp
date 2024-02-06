#ifndef XIEITE_HEADER_CONCEPTS_COMPILE_TIME_EVALUABLE
#	define XIEITE_HEADER_CONCEPTS_COMPILE_TIME_EVALUABLE

#	include <concepts>
#	include <functional>

namespace xieite::concepts {
	template<typename Functor, typename... Arguments>
	concept CompileTimeEvaluable = std::invocable<Functor, Arguments...> && requires(Functor functor, Arguments... arguments) {
		xieite::detail::compileTimeEvaluator<std::invoke(functor, arguments...)>;
	};
}

#endif
