module;

#include <xieite/forward.hpp>

export module xieite:functors.tryConstantArguments;

import std;
import :types.List;
import :types.MaybeConstant;

export namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	requires(xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::is_invocable>::value)
	/* discardable */ constexpr typename xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::invoke_result_t> tryConstantArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::is_nothrow_invocable>::value) {
		return xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::apply([&functor, &arguments...]<typename... MaybeConstantArguments> -> typename xieite::types::List<Arguments...>::template Transform<1, []<typename Argument, typename... First> { return std::type_identity<std::conditional_t<xieite::types::List<Arguments...>::template Slice<sizeof...(First) + 1>::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>::template To<std::is_invocable>::value, xieite::types::MaybeConstant<Argument, true>, Argument>>(); }>::template Prepend<Functor>::template To<std::invoke_result_t> {
			return std::invoke(XIEITE_FORWARD(functor), std::forward_like<MaybeConstantArguments>(arguments)...);
		});
	}
}
