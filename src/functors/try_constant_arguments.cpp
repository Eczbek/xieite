module;

#include <xieite/forward.hpp>
#include <xieite/try_return.hpp>

export module xieite:functors.tryConstantArguments;

import std;
import :types.MaybeConstant;

export namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	requires(std::invocable<Functor, xieite::types::MaybeConstant<Arguments, true>...> || std::invocable<Functor, Arguments...>)
	constexpr decltype(auto) tryConstantArguments(Functor&& functor, Arguments&&... arguments)
	noexcept(std::invocable<Functor, xieite::types::MaybeConstant<Arguments, true>...> ? std::is_nothrow_invocable_v<Functor, xieite::types::MaybeConstant<Arguments, true>...> : std::is_nothrow_invocable_v<Functor, Arguments...>) {
		XIEITE_TRY_RETURN(std::invoke(XIEITE_FORWARD(functor), std::forward_like<xieite::types::MaybeConstant<Arguments, true>>(arguments)...))
		else {
			return std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...);
		}
	}
}
