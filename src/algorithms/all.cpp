module;

#include "../macros/forward.hpp"

export module xieite:algorithms.all;

import std;
import :concepts.Invocable;
import :concepts.NoThrowInvocable;

export namespace xieite::algorithms {
	template<typename... Values, typename Functor>
	requires((... && xieite::concepts::Invocable<Functor, bool(Values)>))
	[[nodiscard]] constexpr bool all(Functor&& functor, Values&&... values)
	noexcept((... && xieite::concepts::NoThrowInvocable<Functor, bool(Values)>)) {
		return (... && std::invoke_r<bool>(functor, XIEITE_FORWARD(values)));
	}
}
