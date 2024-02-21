#ifndef XIEITE_HEADER_CONCEPTS_CONSTANT_EXPRESSION_INVOCABLE
#	define XIEITE_HEADER_CONCEPTS_CONSTANT_EXPRESSION_INVOCABLE

#	include <functional>

namespace xieite::detail {
	template<auto>
	inline constexpr bool constantExpressionEvaluator = true;
}

namespace xieite::concepts {
	template<auto functor, auto... arguments>
	concept ConstantExpressionInvocable = requires {
		xieite::detail::constantExpressionEvaluator<(static_cast<void>(std::invoke(functor, arguments...)), 0)>;
	};
}

#endif
