module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:algorithms.any;

import std;

export namespace xieite::algorithms {
	template<typename... Values, typename Functor>
	[[nodiscard]] constexpr auto any(Functor&& functor, Values&&... values)
	XIEITE_ARROW((... || std::invoke_r<bool>(functor, XIEITE_FORWARD(values))))
}
